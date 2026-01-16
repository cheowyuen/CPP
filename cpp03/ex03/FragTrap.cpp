#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
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

void FragTrap::attack(const std::string& target) {
	if (_energyPoints <= 0)
		std::cout << "FragTrap " << _name << " doesn't have enough energy points\n";
	else if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " doesn't have hit points\n";
	else {
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a positive high five\n";
}
