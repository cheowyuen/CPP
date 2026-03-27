#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
	
	public:
		PmergeMe() = default;
		~PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = default;
		PmergeMe& operator=(const PmergeMe& other) = default;

		void parseInput(char **argv);
		void sortVector();
		void sortDeque();
};

#endif