#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog is created\n";
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog is destroyed\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
	brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof\n";
}

Brain *Dog::getBrain() {
	return brain;
}
