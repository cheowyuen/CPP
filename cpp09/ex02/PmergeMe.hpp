#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <unordered_map>
#include <utility>
#include <iostream>

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

		template <typename T>
		T pairAndSort(T& c) {
			if (c.size() < 2)
				return c;
			int oddNum = -1;
			std::unordered_map<int, int> map;
			T main;
			T pending;
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
			T sorted = pairAndSort(main);

			T sortedP;
			for (size_t i = 0; i < sorted.size(); i++) {
				for (std::unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
					if (it->second == sorted[i]) {
						sortedP.push_back(it->first);
						break;
					}
				}
			}

			if (!map.empty()) {
				for (std::pair<int, int> pair : map) {
					if (pair.second == sorted[0]) {
						sorted.insert(sorted.begin(), pair.first);
						break;
					}
				}
			}

			size_t prev = 0;
			size_t index = 2;
			size_t oriIndex;
			bool last = false;
			if (main.size() <= index) {
				index = main.size() - 1;
				last = true;
			}
			oriIndex = index;
			std::cout << "index: " << index << std::endl;
			std::cout << "size: " << main.size() << std::endl;
			if (main.size() > 1) {
				while (index < main.size()) {
					size_t i = index;
					std::cout << "i: " << i << std::endl;
					std::cout << "prev: " << prev << std::endl;
					while (i > prev) {
						size_t left = 0;
						auto it = std::find(sorted.begin(), sorted.end(), map[sortedP[i]]);
						size_t right = it - sorted.begin();
						while (left < right) {
							size_t mid = (left + right) / 2;
							if (sortedP[i] < sorted[mid])
								right = mid;
							else
								left = mid + 1;
						}
						std::cout << "left: " << left << std::endl;
						std::cout << "value: " << sortedP[i] << std::endl;
						sorted.insert(sorted.begin() + left, sortedP[i]);
						i--;
						std::cout << "i2: " << i << std::endl;
						std::cout << "prev2: " << prev << std::endl;
					}
					size_t temp = index;
					index = (oriIndex + 1) + (prev + 1) * 2;
					std::cout << "main: " << main.size() << std::endl;
					std::cout << "ori: " << oriIndex << std::endl;
					std::cout << "ori prev: " << prev << std::endl;
					if (main.size() <= index &&  !last) {
						index = main.size() - 1;
						last = true;
					}
					oriIndex  = index;
					prev = temp;
					std::cout << "temp: " << temp << std::endl;
					std::cout << "new index: " << index << std::endl;
				}
			}

			if (oddNum != -1) {
				size_t left = 0;
				size_t right = sorted.size();

				while (left < right)
				{
					size_t mid = (left + right) / 2;

					if (oddNum < sorted[mid])
						right = mid;
					else
						left = mid + 1;
				}

				sorted.insert(sorted.begin() + left, oddNum);
			}

			// std::cout << "main: ";
			// for (auto it = main.begin(); it != main.end(); ++it)
			// 	std::cout << *it << " ";
			// std::cout << std::endl;

			// std::cout << "sorted: ";
			// for (auto it = sorted.begin(); it != sorted.end(); ++it)
			// 	std::cout << *it << " ";
			// std::cout << std::endl;

			// std::cout << "pending: ";
			// for (auto it = pending.begin(); it != pending.end(); ++it)
			// 	std::cout << *it << " ";
			// std::cout << std::endl;

			// std::cout << "sortedP: ";
			// for (auto it = sortedP.begin(); it != sortedP.end(); ++it)
			// 	std::cout << *it << " ";
			// std::cout << std::endl;

			return sorted;
		}
};

#endif
