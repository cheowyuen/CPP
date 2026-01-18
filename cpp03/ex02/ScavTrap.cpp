#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ScavTrap("ScavTrap") {}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " copy constructed\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed\n";
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
	else if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " doesn't have hit points\n";
	else if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " doesn't have enough energy points\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
