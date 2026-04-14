#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>
#include <ctime>

Base * generate(void) {
	std::srand(std::time(nullptr));
	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n"; 
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch (std::bad_cast&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch (std::bad_cast&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch (std::bad_cast&) {}
}

int main() {
	for (int i = 0; i < 5; i++) {
		Base* obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
		std::cout << "-----\n";
	}
	return 0;
}
