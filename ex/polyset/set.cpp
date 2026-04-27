#include "set.hpp"

set::set(searchable_bag& b) : bagPtr(&b) {}

set::set(const set& other) : bagPtr(other.bagPtr) {}

set& set::operator=(const set& other) {
	if (this != &other)
		bagPtr = other.bagPtr;
	return *this;
}

set::~set() {}

searchable_bag& set::get_bag() {return *bagPtr;}

const searchable_bag& set::get_bag() const {return *bagPtr;}

void set::insert(int value) {
	if (!bagPtr->has(value))
		bagPtr->insert(value);
}

void set::insert(int *array, int size) {
	for (int i = 0; i < size; i++) 
		insert(array[i]);
}

void set::print() const {
	bagPtr->print();
}

void set::clear() {
	bagPtr->clear();
}

bool set::has(int value) const {
	return bagPtr->has(value);
}
