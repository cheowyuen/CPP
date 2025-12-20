#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	_value = value * 256;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	_value = roundf(value * 256);
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

int Fixed::toInt(void) {
	return _value / 256;
}

float Fixed::toFloat(void) const {
	return _value / 256.0f;
}

