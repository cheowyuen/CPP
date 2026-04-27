#include "set.hpp"

set::set(searchable_bag& b) : bag_ptr(&b) {}

set::set(const set& other) : bag_ptr(other.bag_ptr) {}

set& set::operator=(const set& other) {
	if (this != &other) {
		bag_ptr = other.bag_ptr;
	}
	return *this;
}

set::~set() {}

searchable_bag& set::get_bag() {
	return *bag_ptr;
}

const searchable_bag& set::get_bag() const {
	return *bag_ptr;}

void set::insert (int value) {
	if (!bag_ptr->has(value))
		bag_ptr->insert(value);
}

void set::insert (int *array, int size) {
	for (int i = 0; i < size; i++)
		insert(array[i]);
}

void set::print() const {
	bag_ptr->print();
}

void set::clear() {
	bag_ptr->clear();
}

bool set::has(int value) const {
	return bag_ptr->has(value);
}
