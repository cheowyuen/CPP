#include "iter.hpp"
#include <string>

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
	const std::string constArr[] = {"a", "b", "c"};
	iter(constArr, 3, printInt<std::string>);
	return 0;
}
