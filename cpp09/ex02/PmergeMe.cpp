#include "PmergeMe.hpp"
#include <iostream>
#include <set>

int PmergeMe::parseInput(char **argv) {
	int i = 1;
	std::set<int> seen;
	while (argv[i]) {
		try {
			size_t pos;
			int token = std::stoi(argv[i],  &pos);
			if (argv[i][pos] != '\0' || token < 0  || argv[i][0] == '\0') {
				std::cerr << "Error\n";
				return -1;
			}
			if (!seen.insert(token).second) {
				std::cerr << "Error: Duplicate numbers\n";
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
	return 0;
}

void PmergeMe::sortVector() {
	std::cout << "Vector before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << "\n";
	pairAndSort(_vec);
	std::cout << "Vector after:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << "\n";
	return;
}

void PmergeMe::sortDeque() {
	std::cout << "Deque before:";
	for (size_t i = 0; i < _deq.size(); i++)
		std::cout << " " << _deq[i];
	std::cout << "\n";
	pairAndSort(_deq);
	std::cout << "Deque after:";
	for (size_t i = 0; i < _deq.size(); i++)
		std::cout << " " << _deq[i];
	std::cout << "\n";
	return;
}
