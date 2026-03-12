#ifndef ITER_HPP
#define ITER_HPP

#include <cstdint>

template <typename T, typename Func>
void iter(T* arr, const int len, Func func) {
	for (int i = 0; i < len; i++) 
		func(arr[i]);
};

#endif