#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
	type = "Cat";
	std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructed\n";
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructed\n";
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}

Brain &Cat::getBrain() const {
	return *brain;
}
