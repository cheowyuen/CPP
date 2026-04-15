#include "PmergeMe.hpp"
#include <iostream>

int PmergeMe::parseInput(char **argv) {
	int i = 1;
	while (argv[i]) {
		try {
			int token = std::stoi(argv[i]);
			if (token < 0) {
				std::cerr << "Error\n";
				return -1;
			}
			_vec.push_back(token);
			_deq.push_back(token);
		}
		catch (std::exception&) {
			std::cerr << "Error\n";
			return -1;
		}
		i++;
	}
	std::cout << "Vector before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << "\n";
	std::cout << "Deque before:";
	for (size_t i = 0; i < _deq.size(); i++)
		std::cout << " " << _deq[i];
	std::cout << "\n";
	pairAndSort(_vec);
	// pairAndSort(_deq);
	return 0;
}

void PmergeMe::sortVector() {
	return;
}

void PmergeMe::sortDeque() {
	return;
}
