#include "random_engine.h"

#include <random>
#include <time.h>

namespace random
{
	void seed(uint32_t num)
	{
		if (num == UINT32_MAX)
			srand(time(nullptr));
		else
			srand(num);
	}

	float get_float(float from, float to)
	{
		float num = static_cast<float>(rand()) / RAND_MAX;
		return from + num * (to - from);
	}
}