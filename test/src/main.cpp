#include <iostream>

#define LOG_OUT(x) std::cout << x << std::endl

#include "backpropagation.h"

int main(int argc, char* argv[])
{
	random::seed(2);
	NeuralNetwork nn({ 2, 2 });

	values_t result = nn.feed({ 0.2f, 0.3f });

	values_log_out(result);

	return 0;
}