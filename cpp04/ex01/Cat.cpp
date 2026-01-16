#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat is created\n";
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat is destroyed\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}
