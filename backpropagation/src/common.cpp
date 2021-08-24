#include "common.h"

void values_log_out(const values_t& values)
{
	for (int i = 0; i < values.size(); i++)
		log_out_append(values[i] << (i == values.size() - 1 ? "" : ", "));
}