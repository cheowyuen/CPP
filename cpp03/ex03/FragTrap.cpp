#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : FragTrap("FragTrap") {}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " copy constructed\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a positive high five\n";
}
