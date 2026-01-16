#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("") {
	std::cout << "Wrong Animal is created\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal is destroyed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Grrr\n";
}
