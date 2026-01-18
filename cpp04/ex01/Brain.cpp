#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructed\n";
}

Brain::Brain(const Brain &other) {
	for(int i = 1; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructed\n";
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for(int i = 1; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructed\n";
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

const std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}
