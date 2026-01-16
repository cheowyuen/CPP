#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	_value = num << _bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	_value = roundf(num * (1 << _bits));
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
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

int Fixed::toInt(void) const {
	return _value >> _bits;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _bits);
}
	