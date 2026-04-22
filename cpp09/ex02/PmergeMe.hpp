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
		void sortVector();
		void sortDeque();

		template <typename Container>
		size_t binary_insert(const Container& sorted, size_t right, int value)
		{
			size_t left = 0;
			while (left < right)
			{
				size_t mid = (left + right) / 2;
				if (value < sorted[mid])
					right = mid;
				else
					left = mid + 1;
			}
			return left;
		}

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
					map[c[i]] = c[i + 1];
					main.push_back(c[i + 1]);
					pending.push_back(c[i]);
				}
				else {
					map[c[i + 1]] = c[i];
					main.push_back(c[i]);
					pending.push_back(c[i + 1]);
				}
			}
			if (c.size() % 2 != 0)
				oddNum = c.back();
			Container sorted = pairAndSort(main);

			Container sortedP;
			for (size_t i = 0; i < sorted.size(); i++) {
				for (std::unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
					if (it->second == sorted[i]) {
						sortedP.push_back(it->first);
						break;
					}
				}
			}

			for (std::pair<int, int> pair : map) {
				if (pair.second == sorted[0]) {
					sorted.insert(sorted.begin(), pair.first);
					break;
				}
			}

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
					auto it = std::find(sorted.begin(), sorted.end(), map[sortedP[i]]);
					size_t left = binary_insert(sorted, it - sorted.begin(), sortedP[i]);
					sorted.insert(sorted.begin() + left, sortedP[i]);
					i--;
				}
				size_t temp = index;
				index = (index + 1) + (prev + 1) * 2;
				if (main.size() <= index &&  !last) {
					index = main.size() - 1;
					last = true;
				}
				prev = temp;
			}

			if (oddNum != -1) {
				size_t left = binary_insert(sorted, sorted.size(), oddNum);
				sorted.insert(sorted.begin() + left, oddNum);
			}

			return sorted;
		}
};

#endif
