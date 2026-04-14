#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main( void ) {
	Array<int> a;
	std::cout << "---- Array a ----\n";
	std::cout << "size: " << a.size() << "\n";

	Array<int> b(5);
	std::cout << "---- Array b ----\n";
	std::cout << "size: " << b.size() << "\n";
	for (int i = 0; i < 5; i++) {
		b[i] = i;
		std::cout << b[i] << " ";
	}
	std::cout << "\n";

	Array<int> c(b);
	std::cout << "---- Array c ----\n";
	std::cout << "size: " << c.size() << "\n";
	for (int i = 0; i < 5; i++) {
		c[i] = i;
		std::cout << c[i] << " ";
	}
	std::cout << "\n";

	Array<int> d;
	d = b;
	std::cout << "---- Array d ----\n";
	std::cout << "size: " << d.size() << "\n";
	for (int i = 0; i < 5; i++) {
		d[i] = i;
		std::cout << d[i] << " ";
	}
	std::cout << "\n";

	std::cout << "\n---- Out of bounds test ----\n";
    try {
        std::cout << b[100] << "\n";
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

	return 0;
}
