#pragma once

#include <stdint.h>
#include <limits>

#include "common.h"

namespace random
{
	API void seed(uint32_t num = UINT32_MAX);
	API float get_float(float from = 0.0f, float to = 1.0f);
}