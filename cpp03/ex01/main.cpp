#include "ScavTrap.hpp"

int main() {
	ScavTrap scavTrap("Nibble");
	scavTrap.attack("Wobble");
	scavTrap.beRepaired(1);
	scavTrap.takeDamage(101);
	scavTrap.guardGate();
	scavTrap.attack("Wobble");
	scavTrap.beRepaired(1);
	scavTrap.takeDamage(1);
	return 0;
}
