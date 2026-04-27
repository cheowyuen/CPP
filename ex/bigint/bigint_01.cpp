#include "bigint.hpp"
#include <sstream>
#include <algorithm>

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int n) {
	std::stringstream ss;
	ss << n;
	digits = ss.str();
}

bigint::bigint(const bigint& other) {
	digits = other.digits;
}

bigint::~bigint() {}

const std::string& bigint::getDigits() const {
	return digits;
}

std::string bigint::addStrings(const std::string& a, const std::string& b) {
	std::string res;
	int carry = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;
	while (i >= 0 || j >=0 || carry) {
		int sum = carry;
		if (i >= 0) {
			sum += a[i--] - '0';
		}
		if (j >= 0) {
			sum += b[j--] - '0';
		}
		res.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	std::reverse(res.begin(), res.end());
	return res;
}

void bigint::normalize() {
	size_t pos = digits.find_first_not_of("0");
	if (pos == std::string::npos) 
		digits = "0";
	else if (pos > 0)
		digits.erase(0, pos);
}

size_t bigint::toSizeT() const {
	size_t n = 0;
	for (size_t i = 0; i < this->digits.size(); i++) {
		n = n * 10 + (this->digits[i] - '0');
	}
	return n;
}

bigint& bigint::operator=(const bigint& other) {
	if (this != &other) {
		digits = other.digits;
	}
	return *this;
}

bigint bigint::operator+(const bigint& other) const {
	bigint res;
	res.digits = addStrings(this->digits, other.digits);
	res.normalize();
	return res;
}

bigint& bigint::operator+=(const bigint& other) {
	this->digits = addStrings(this->digits, other.digits);
	this->normalize();
	return *this;
}

bigint& bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint tmp(*this);
	++*this;
	return tmp;
}

bigint bigint::operator<<(size_t n) const {
	if (this->digits == "0")
		return *this;
	bigint res(*this);
	res.digits.append(n, '0');
	return res;
}

bigint& bigint::operator<<=(size_t n) {
	if (this->digits == "0")
		return *this;
	this->digits.append(n, '0');
	return *this;
}

bigint bigint::operator>>(size_t n) const {
	bigint res(*this);
	if (n >= this->digits.size())
		res.digits = "0";
	else
		res.digits.erase(this->digits.size() - n);
	return res;
}

bigint& bigint::operator>>=(size_t n) {
	if (n >= this->digits.size())
		this->digits = "0";
	else
		this->digits.erase(this->digits.size() - n);
	return *this;
}

bigint bigint::operator<<(const bigint& other) const {
	return (*this) << other.toSizeT();
}

bigint bigint::operator>>(const bigint& other) const {
	return (*this) >> other.toSizeT();
}

bigint& bigint::operator<<=(const bigint& other) {
	return (*this) <<= other.toSizeT();
}

bigint& bigint::operator>>=(const bigint& other) {
	return (*this) >>= other.toSizeT();
}

bool bigint::operator<(const bigint& other) const {
	if (this->digits.size() != other.digits.size())
		return this->digits.size() < other.digits.size();
	return this->digits < other.digits;
}

bool bigint::operator>(const bigint& other) const {
	return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
	return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
	return !(*this < other);
}

bool bigint::operator==(const bigint& other) const {
	return this->digits == other.digits;
}

bool bigint::operator!=(const bigint& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const bigint& b) {
	os << b.getDigits();
	return os;
}
