#include "vect2.hpp"

vect2::vect2() {
	data[0] = 0;
	data[1] = 0;
}

vect2::vect2(int x, int y) {
	data[0] = x;
	data[1] = y;
}

vect2::vect2(const vect2& other) {
	data[0] = other.data[0];
	data[1] = other.data[1];
}

vect2& vect2::operator=(const vect2& other) {
	if (this != &other) {
		data[0] = other.data[0];
		data[1] = other.data[1];
	}
	return *this;
}

vect2::~vect2() {}

int& vect2::operator[](int index) {
	return data[index];
}

const int& vect2::operator[](int index) const {
	return data[index];
}

vect2 vect2::operator+(const vect2& other) const {
	return vect2(data[0] + other.data[0], data[1] + other.data[1]);
}

vect2 vect2::operator-(const vect2& other) const {
	return vect2(data[0] - other.data[0], data[1] - other.data[1]);
}

vect2 vect2::operator*(int scalar) const {
	return vect2(data[0] * scalar, data[1] * scalar);
}

vect2& vect2::operator+=(const vect2& other) {
	data[0] += other.data[0];
	data[1] += other.data[1];
	return *this;
}

vect2& vect2::operator-=(const vect2& other) {
	data[0] -= other.data[0];
	data[1] -= other.data[1];
	return *this;
}

vect2& vect2::operator*=(int scalar) {
	data[0] *= scalar;
	data[1] *= scalar;
	return *this;
}

vect2 vect2::operator-() const {
	return vect2(-data[0], -data[1]);
}

vect2& vect2::operator++() {
	++data[0];
	++data[1];
	return *this;
}

vect2& vect2::operator--() {
	--data[0];
	--data[1];
	return *this;
}

vect2 vect2::operator++(int) {
	vect2 tmp(*this);
	++(*this);
	return tmp;
}

vect2 vect2::operator--(int) {
	vect2 tmp(*this);
	--(*this);
	return tmp;
}

bool vect2::operator==(const vect2& other) const {
	return data[0] == other.data[0] && data[1] == other.data[1];
}

bool vect2::operator!=(const vect2& other) const {
	return !(*this == other);
}

vect2 operator*(int scalar, const vect2& v) {
	return vect2(v[0] * scalar, v[1] * scalar);
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
	os << "{" << v[0] << ", " << v[1] << "}" << std::endl;
	return os;
}
