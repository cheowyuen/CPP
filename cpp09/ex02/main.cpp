#include "PmergeMe.hpp"
#include <chrono>


int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error\n";
		return 1;
	}
	
	PmergeMe p;
	if (p.parseInput(argv) == -1)
		return 1;

	auto start = std::chrono::steady_clock::now();
	p.sortVector();
	auto end = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration<double, std::micro>(end - start).count();

	auto startD = std::chrono::steady_clock::now();
	p.sortDeque();
	auto endD = std::chrono::steady_clock::now();
	auto durationD = std::chrono::duration<double, std::micro>(endD - startD).count();

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << duration << " us\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << durationD << " us\n";

	return 0;
}