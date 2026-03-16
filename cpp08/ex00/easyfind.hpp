#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
class easyfind {
	public:
		easyfind();
		easyfind(T _type, int _value);
		easyfind(const easyfind& other);
		easyfind& operator=(const easyfind& other);
		~easyfind();
};

#include "easyfind.tpp"

#endif