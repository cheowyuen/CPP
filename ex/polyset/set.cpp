#include "set.hpp"

set::set(searchable_bag *b) : bag(b) {}

set::set(const set &other) : bag(other.bag) {}

set &set::operator=(const set &other) {
    if (this != &other)
        bag = other.bag;
    return *this;
}

set::~set() {}

void set::insert(int value) {
    if (!bag->search(value))
        bag->add(value);
}

void set::remove(int value) {
    bag->remove(value);
}

bool set::contains(int value) const {
    return bag->search(value);
}