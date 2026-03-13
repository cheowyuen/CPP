#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) {
	_array = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
		_array[i] = other[i];
	_size = other._size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _array;
		_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			_array[i] = other[i];
		_size = other._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {}

#endif
