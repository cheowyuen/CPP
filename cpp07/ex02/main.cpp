#include "Array.hpp"
#include <iostream>

int main( void ) {
	Array<int> arrayA(5);
	for (int i = 0; i < 5; i++)
		arrayA[i] = i;
	Array<int> arrayB(arrayA);
	for (int i = 0; i < 5; i++) {
		std::cout << "arrayB[" << i << "]: " << arrayB[i] << "\n";
	}
	return 0;
}
