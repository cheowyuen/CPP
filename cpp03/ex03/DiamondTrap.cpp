#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : DiamondTrap("DiamondTrap") {}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), _name(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " constructed\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), _name(other._name) {
	std::cout << "DiamondTrap " << _name << " copy constructed\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destroyed\n";
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << _name << ", my ClapTrap name is " << ClapTrap::_name << "\n";
}
