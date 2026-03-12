#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
	public:
		C() = default;
		~C() = default;
		C(const C &other) = default;
		C &operator=(const C &other) = delete;
};

#endif