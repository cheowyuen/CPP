#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat is created\n";
}

Cat::~Cat() {
	std::cout << "Cat is destroyed\n";
}

Cat::Cat(const Cat &other) : Animal(other) {}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}
