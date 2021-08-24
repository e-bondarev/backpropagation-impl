#pragma once

#ifdef BACKPROPAGATION_SHARED
#	define API __declspec(dllexport)
#else
#	define API 
#endif