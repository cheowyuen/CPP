#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &_name, Weapon &_weapon) : name(_name), weapon(_weapon) {}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
