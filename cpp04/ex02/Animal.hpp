#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	protected:
		Animal();
		std::string type;

	public:
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		const std::string &getType() const;
		virtual void makeSound() const = 0;
};

#endif