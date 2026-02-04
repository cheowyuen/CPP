#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	j->makeSound();
	i->makeSound();
    delete j;
    delete i;

	std::cout << "\n=== Test arrray ===" << std::endl;
    Animal* animals[10];
    for (int index = 0; index < 5; index++)
        animals[index] = new Dog();
    for (int index = 5; index < 10; index++)
        animals[index] = new Cat();
    for (int index = 0; index < 10; index++)
        animals[index]->makeSound();
    for (int index = 0; index < 10; index++) {
        delete animals[index];
	}

	std::cout << "\n=== Test deep copy ===" << std::endl;
    Dog dog1;
    dog1.getBrain().setIdea(0, "Eat");
	Dog dog2(dog1);
    dog2.getBrain().setIdea(0, "Sleep");
    std::cout << "dog1 Brain idea 0: " << dog1.getBrain().getIdea(0) << std::endl;
    std::cout << "dog2 Brain idea 0: " << dog2.getBrain().getIdea(0) << std::endl;
	
    return 0;
}
