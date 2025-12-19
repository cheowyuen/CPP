#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &_name) : name(_name), weapon(nullptr) {}

void HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " has no weapon\n";
}

void HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}
