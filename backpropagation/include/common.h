#pragma once

#ifdef BACKPROPAGATION_SHARED
#	define API __declspec(dllexport)
#else
#	define API 
#endif

#include <vector>
#include <iostream>
#include <stdint.h>

class Neuron;
class Layer;
class NeuralNetwork;

using value_t = float;
using values_t = std::vector<value_t>;
using neurons_t = std::vector<Neuron>;
using layers_t = std::vector<Layer>;
using layout_t = std::vector<uint32_t>;

#define to_value_t(x) static_cast<value_t>(x)

#define log_out_append(x) std::cout << x
#define log_out(x) log_out_append(x << std::endl)

void values_log_out(const values_t& values);