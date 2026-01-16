#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("") {
	std::cout << "Animal is created\n";
}

Animal::~Animal() {
	std::cout << "Animal is destroyed\n";
}

Animal::Animal(const Animal &other) : type(other.type) {}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Grrr\n";
}
