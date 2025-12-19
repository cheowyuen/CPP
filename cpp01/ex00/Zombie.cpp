#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &_name) : name(_name) {}

Zombie::~Zombie()
{
	std::cout << name << " is being destroyed!\n";
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
