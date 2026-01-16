#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "Wrong Cat is created\n";
}

WrongCat::~WrongCat() {
	std::cout << "Wrong Cat is destroyed\n";
}

WrongCat::WrongCat(const WrongCat &other) {
	type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow\n";
}
