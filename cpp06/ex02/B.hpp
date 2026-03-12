#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base {
	public:
		B() = default;
		~B() = default;
		B(const B &other) = default;
		B &operator=(const B &other) = delete;
};

#endif