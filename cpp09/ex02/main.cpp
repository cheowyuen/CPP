#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char** argv) {
	(void)argc;
	PmergeMe p;
	if (p.parseInput(argv) == -1)
		return 1;

	clock_t start = clock();
	p.sortVector();
	clock_t end = clock();
	double time_us = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

	clock_t start2 = clock();
	p.sortDeque();
	clock_t end2 = clock();
	double time_us2 = (double)(end2 - start2) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time_us << " us\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << time_us2 << " us\n";

	return 0;
}