#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructed\n";
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructed\n";
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}
