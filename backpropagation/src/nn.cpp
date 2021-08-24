#include "nn.h"

#include "random_engine.h"

#include <assert.h>

value_t SIGMOID(value_t x)
{
	return to_value_t(1.0f) / (to_value_t(1.0f) + exp(-x));
}

Neuron::Neuron() : result{to_value_t(0.0f)}
{

}

Layer::Layer() : prev_layer{nullptr}
{

}

void Layer::initialize(Layer* p_prev_layer)
{
	prev_layer = p_prev_layer;

	for (int i = 0; i < neurons.size(); i++)
		for (int j = 0; j < prev_layer->neurons.size(); j++)
			neurons[i].weights.push_back(random::get_float());
}

void Layer::set_values(const values_t& values)
{
	assert(neurons.size() == values.size());

	for (int i = 0; i < neurons.size(); i++)
		neurons[i].result = values[i];
}

void Layer::get_values(values_t& values) const
{
	assert(neurons.size() == values.size());

	for (int i = 0; i < neurons.size(); i++)
		values[i] = neurons[i].result;
}

void Layer::operator()()
{
	for (int i = 0; i < neurons.size(); i++)
	{
		value_t res{to_value_t(0.0f)};

		for (int prev_i = 0; prev_i < prev_layer->neurons.size(); prev_i++)
		{
			res += prev_layer->neurons[prev_i].result * neurons[i].weights[prev_i];
		}

		neurons[i].result = SIGMOID(res);
	}
}

const values_t& NeuralNetwork::feed(const values_t& input)
{
	Layer& first_layer = layers[0];
	Layer& last_layer = layers[layers.size() - 1];

	first_layer.set_values(input);

	for (int i = 1; i < layers.size(); i++)
		layers[i]();

	last_layer.get_values(output);
	return output;
}

NeuralNetwork::NeuralNetwork(const layout_t& p_layout) : layout{p_layout}
{
	layers.resize(layout.size());

	for (int i = 0; i < layers.size(); i++)
		layers[i].neurons.resize(layout[i]);

	for (int i = 1; i < layers.size(); i++)
		layers[i].initialize(&layers[i - 1]);

	const Layer& last_layer = layers[layers.size() - 1];
	output.resize(last_layer.neurons.size(), to_value_t(0.0f));
}