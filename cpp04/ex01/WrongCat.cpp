#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "Wrong Cat constructed\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Wrong Cat copy constructed\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Wrong Cat destructed\n";
}

void WrongCat::makeSound() const {
	std::cout << "Meow\n";
}
