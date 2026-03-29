#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	(void)argc;
	PmergeMe sort;
	if (sort.parseInput(argv) == -1)
		return 1;
	sort.sortVector();
	sort.sortDeque();
	return 0;
}