#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "Invalid number of arguments\n";
	ScalarConverter::convert(argv[1]);
}
