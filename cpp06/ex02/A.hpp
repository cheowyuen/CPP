#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
	public:
		A() = default;
		~A() = default;
		A(const A &other) = default;
		A &operator=(const A &other) = delete;
};

#endif