#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error\n";
		return 1;
	}
	RPN rpn;
	if (rpn.calculate(argv[1]) == -1)
		return 1;
	return 0;
}
