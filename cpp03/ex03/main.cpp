#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	DiamondTrap diamond("Nibble");
	diamond.attack("Wobble");
	diamond.beRepaired(1);
	diamond.takeDamage(101);
	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.attack(("Wobble"));
	diamond.beRepaired(1);
	diamond.takeDamage(1);
	return 0;
}
