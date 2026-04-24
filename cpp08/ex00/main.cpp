#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <exception>

int main() {
	{
		std::vector<int> c{1, 2, 3};
		std::vector<int>::iterator it = easyfind(c, 2);
		int index = it - c.begin();
		std::cout << "Value found at index " << index << ": " << *it << "\n";
		try {
			easyfind(c, 10);
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << "\n";
		}
	}

	{
		std::vector<int> c{1, 1, 1};
		std::vector<int>::iterator it = easyfind(c, 1);
		int index = it - c.begin();
		std::cout << "Value found at index " << index << ": " << *it << "\n";
	}

	{
		std::cout << "---- const ----"  << "\n";
		const std::list<int> c{4, 5, 6};
		std::list<int>::const_iterator it = easyfind(c, 6);
		int index = std::distance(c.begin(), it);
		std::cout << "Value found at index " << index << ": " << *it << "\n";
		try {
			easyfind(c, 1);
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << "\n";
		}
	}

    return 0;
}
