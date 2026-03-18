#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main( void ) {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	auto i = easyfind(v, 2);
	std::cout << *i << "\n";
	try {
		easyfind(v, 10);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
 