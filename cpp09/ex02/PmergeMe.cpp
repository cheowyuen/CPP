#include "PmergeMe.hpp"
#include <iostream>
#include <set>
#include <chrono>

int PmergeMe::parseInput(char **argv) {
	int i = 1;
	std::set<int> input;
	while (argv[i]) {
		try {
			size_t pos;
			int token = std::stoi(argv[i],  &pos);
			if (argv[i][pos] != '\0' || token < 0  || argv[i][0] == '\0') {
				std::cerr << "Error\n";
				return -1;
			}
			if (!input.insert(token).second) {
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

void PmergeMe::sort(int numCount) {
	size_t n = _vec.size();
	std::cout << "Before:";
	for (size_t i = 0; i < n; i++)
		std::cout << " " << _vec[i];
	std::cout << "\n";

	auto start = std::chrono::steady_clock::now();
	_vec = pairAndSort(_vec);
	auto end = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration<double, std::micro>(end - start).count();

	auto startD = std::chrono::steady_clock::now();
	_deq = pairAndSort(_deq);
	auto endD = std::chrono::steady_clock::now();
	auto durationD = std::chrono::duration<double, std::micro>(endD - startD).count();

	std::cout << "After:";
	for (size_t i = 0; i < n; i++)
		std::cout << " " << _vec[i];
	std::cout << "\n";

	std::cout << "Time to process a range of " << numCount << " elements with std::vector : " << duration << " us\n";
	std::cout << "Time to process a range of " << numCount << " elements with std::deque : " << durationD << " us\n";
	std::cout << "Comparison count: " << _comparisonCount << "\n";
}
