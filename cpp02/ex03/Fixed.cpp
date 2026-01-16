#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int num) {
	_value = num << _bits;
}

Fixed::Fixed(const float num) {
	_value = roundf(num * (1 << _bits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &other) const {
	return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return _value < other._value;
}
	
bool Fixed::operator>=(const Fixed &other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return _value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long long a = static_cast<long long>(_value);
	long long b = static_cast<long long>(other._value);
	result._value = static_cast<int>((a * b) / (1 << _bits));
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	long long a = static_cast<long long>(_value);
	long long b = static_cast<long long>(other._value);
	result._value = static_cast<int>((a << _bits) / b);
	return result;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	_value++;
	return old;
}

Fixed &Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	_value--;
	return old;
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
