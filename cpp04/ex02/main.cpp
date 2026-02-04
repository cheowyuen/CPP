#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// Animal meta;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	j->makeSound();
	i->makeSound();
    delete j;
    delete i;

    return 0;
}
