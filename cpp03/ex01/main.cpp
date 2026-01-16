#include "ScavTrap.hpp"

int main() {
	ScavTrap scavTrap("Nibble");
	scavTrap.attack("Wobble");
	scavTrap.beRepaired(1);
	scavTrap.takeDamage(1);
	scavTrap.guardGate();
	for (int i = 0; i < 9; i++) {
		scavTrap.attack("Wobble");
	}
	scavTrap.beRepaired(1);
	return 0;
}
