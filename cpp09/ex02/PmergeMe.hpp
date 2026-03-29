#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <unordered_map>
#include <utility>

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
		void pairAndSort(T& c) {
			if (c.size() < 2)
				return;
			int oddNum = -1;
			std::unordered_map<int, int> map;
			for (size_t i = 0; i + 1 < c.size(); i += 2) {
				if (c[i] < c[i + 1])
					map[c[i]] = c[i + 1];
				else
					map[c[i + 1]] = c[i];
			}
			if (c.size() % 2 != 0)
				oddNum = c.back();
			std::vector<int> main;
			std::vector<int> pending;
			for (std::unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
				main.push_back(it->second);
				pending.push_back(it->first);
			}
			pairAndSort(main);
			if (!map.empty()) {
				for (std::pair<int, int> pair : map) {
					if (pair.second == main[0]) {
						main.insert(main.begin(), pair.first);
						break;
					}
				}
			}
			int prev = 1;
			int index = 3;
			while (index <= main.size()) {
				int j = index - 1;
				while (j > prev - 1) {
					int pos = 0;
					std::vector<int>::iterator it = std::find(main.begin(), main.end(), map[pending[j]]);
					if (it != main.end())
						pos = std::distance(main.begin(), it);
					main.insert(main[pos], pending[j]);
					j--;
				}
				int temp = index;
				index = index + prev * 2;
				prev = index;
			}
		}
};

#endif

// struct element {
// 				int main;
// 				int pending;
// 			};
// 			std::vector<element> pairs;
// 			for (size_t i = 0; i + 1 < c.size(); i += 2) {
// 				if (c[i] > c[i + 1])
// 					pairs.push_back({c[i], c[i + 1]});
// 				else
// 					pairs.push_back({c[i + 1], c[i]});
// 			}
// 			if (c.size() % 2 != 0)
// 				oddNum = c.back();
// 			std::vector<int> mainSeq;
// 			for (element p : pairs)
// 				mainSeq.push_back(p.main);
// 			pairAndSort(mainSeq);
// 			if (!pairs.empty())
// 				mainSeq.insert(mainSeq.begin(), pairs[0].pending)
// 			int prev = 1;
// 			int index = 3;
// 			while (index <= mainSeq.size()) {
// 				int j = index - 1;
// 				while (j > prev - 1) {
// 					int pos = 0;

// 					for (size_t i = 0; i < mainSeq.size(); i++) {
// 						if (pairs[i].pending = pairs[j].pending) {
// 							pos = i; 
// 						}
// 					}
// 					mainSeq.insert(mainSeq[pos], pairs[j].pending);
// 					j--;
// 				}
// 				int temp = index;
// 				index = index + prev * 2;
// 				prev = index;
// 			}
