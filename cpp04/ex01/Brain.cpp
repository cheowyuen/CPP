#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain is created\n";
}

Brain::~Brain() {
	std::cout << "Brain is destroyed\n";
}

Brain::Brain(const Brain &other) {
	for(int i = 1; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for(int i = 1; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}
