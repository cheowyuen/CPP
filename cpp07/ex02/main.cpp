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
	for (unsigned int i = 0; i < b.size(); i++) {
		b[i] = i;
		std::cout << b[i] << " ";
	}

	Array<int> c(b);
	std::cout << "\n---- Array c ----\n";
	std::cout << "size: " << c.size() << "\n";
	for (unsigned int i = 0; i < c.size(); i++) {
		c[i] = i;
		std::cout << c[i] << " ";
	}

	Array<std::string> d(3);
	d[0] = "hello";
	d[1] = "world";
	d[2] = "!";
	std::cout << "\n---- Array d ----\n";
	std::cout << "size: " << d.size() << "\n";
	for (unsigned int i = 0; i < d.size(); i++) {
		std::cout << d[i] << " ";
	}

	Array<std::string> e;
	e = d;
	std::cout << "\n---- Array e ----\n";
	std::cout << "size: " << e.size() << "\n";
	for (unsigned int i = 0; i < e.size(); i++) {
		std::cout << e[i] << " ";
	}

	const Array<int> f(3);
	std::cout << "\n---- Array f ----\n";
	std::cout << "size: " << f.size() << "\n";
	for (unsigned int i = 0; i < f.size(); i++) {
		std::cout << f[i] << " ";
	}

	std::cout << "\n---- Out of bounds test ----\n";
    try {
        std::cout << b[100] << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
	try {
        std::cout << f[3] << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

	return 0;
}
