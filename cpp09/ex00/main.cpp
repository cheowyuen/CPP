#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	BitcoinExchange btc;
	if (btc.loadDatabase() == -1)
		return 1;
	if (btc.processInput(argv[1]) == -1)
		return 1;
	return 0;
}
