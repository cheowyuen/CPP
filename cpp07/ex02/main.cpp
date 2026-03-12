#include "iter.hpp"
#include <iostream>

template <typename T>
void multiplyTen(T& value) {
	value *= 10;
}

template <typename T>
void printInt(const T& value) {
	std::cout << value << "\n";
}

int main( void ) {
	int intArr[] = {1, 2, 3};
	iter(intArr, 3, multiplyTen<int>);
	for (int i = 0; i < 3; i++)
		std::cout << intArr[i] << "\n";
	const int constArr[] = {4, 5, 6};
	iter(constArr, 3, printInt<int>);
	return 0;
}
