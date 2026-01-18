#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructed\n";
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructed\n";
}

void Dog::makeSound() const {
	std::cout << "Woof\n";
}
