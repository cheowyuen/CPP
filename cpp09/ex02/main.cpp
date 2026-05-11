#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error\n";
		return 1;
	}
	
	PmergeMe p;
	if (p.parseInput(argv) == -1)
		return 1;

	p.sort(argc - 1);

	return 0;
}