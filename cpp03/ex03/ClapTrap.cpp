#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap " << _name << " copy constructed\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed\n";
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points\n";
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " doesn't have hit points\n";
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (static_cast<int>(amount) >= _hitPoints)
	{
		std::cout << "ClapTrap " << _name << " loses " << _hitPoints << " hit points\n";
		_hitPoints = 0; 
	}
	else
	{
		std::cout << "ClapTrap " << _name << " loses " << amount << " hit points\n";
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " regains " << amount << " hit points\n";
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " doesn't have hit points\n";
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points\n";
}
