#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	if (btc.processInput(argv[1]) == -1)
		return 1;
	return 0;
}
