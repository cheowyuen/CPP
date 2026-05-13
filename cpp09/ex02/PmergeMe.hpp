#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

	public:
		PmergeMe() = default;
		~PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = default;
		PmergeMe& operator=(const PmergeMe& other) = default;

		int parseInput(char **argv);
		void sort(int numCount);

		template <typename Container>
		Container pairAndSort(Container& c) {
			if (c.size() < 2)
				return c;
			int oddNum = -1;
			std::unordered_map<int, int> map;
			Container main;
			Container pending;
			for (size_t i = 0; i + 1 < c.size(); i += 2) {
				if (c[i] < c[i + 1]) {
					map[c[i + 1]] = c[i];
					main.push_back(c[i + 1]);
				}
				else {
					map[c[i]] = c[i + 1];
					main.push_back(c[i]);
				}
			}
			if (c.size() % 2 != 0)
				oddNum = c.back();
			Container sorted = pairAndSort(main);

			for (size_t i = 0; i < sorted.size(); ++i)
				pending.push_back(map[sorted[i]]);

			sorted.insert(sorted.begin(), pending[0]);

			size_t prev = 0;
			size_t index = 2;
			bool last = false;
			if (main.size() <= index) {
				index = main.size() - 1;
				last = true;
			}
			while (index < main.size()) {
				size_t i = index;
				while (i > prev) {
					auto it = std::upper_bound(sorted.begin(), sorted.end(), pending[i]);
					sorted.insert(it, pending[i]);
					i--;
				}
				size_t temp = index;
				index = ((index + 1) + (prev + 1) * 2) - 1;
				if (main.size() <= index &&  !last) {
					index = main.size() - 1;
					last = true;
				}
				prev = temp;
			}

			if (oddNum != -1) {
				auto it = std::upper_bound(sorted.begin(), sorted.end(), oddNum);
				sorted.insert(it, oddNum);
			}

			return sorted;
		}
};

#endif
