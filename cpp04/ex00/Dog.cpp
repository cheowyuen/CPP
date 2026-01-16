#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog is created\n";
}

Dog::~Dog() {
	std::cout << "Dog is destroyed\n";
}

Dog::Dog(const Dog &other) : Animal(other) {}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof\n";
}
