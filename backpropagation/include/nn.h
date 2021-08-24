#pragma once

#include "common.h"

API class Neuron
{
friend class Layer;
friend class NeuralNetwork;

public:
	Neuron();

private:
	values_t weights;
	value_t result;
};

API class Layer
{
friend class NeuralNetwork;

public:
	Layer();

private:
	void operator()();

	void initialize(Layer* p_prev_layer);

	void set_values(const values_t& values);
	void get_values(values_t& values) const;

	neurons_t neurons;
	Layer* prev_layer;
};

API class NeuralNetwork
{
public:
	NeuralNetwork(const layout_t& p_layout);
	
	const values_t& feed(const values_t& input);

private:
	layers_t layers;
	layout_t layout;
	values_t output;
};