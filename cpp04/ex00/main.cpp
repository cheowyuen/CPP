#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	
	const WrongAnimal* animal = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	animal->makeSound();
	delete cat;
	delete animal;

	return 0;
}
