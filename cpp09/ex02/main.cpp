#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	(void)argc;
	PmergeMe sort;
	sort.parseInput(argv);
	sort.sortVector();
	sort.sortDeque();
	return 0;
}