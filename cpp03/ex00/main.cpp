#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap("Nibble");
	clapTrap.attack("Wobble");
	clapTrap.beRepaired(1);
	clapTrap.takeDamage(1);
	for (int i = 0; i < 9; i++) {
		clapTrap.attack("Wobble");
	}
	clapTrap.beRepaired(1);
	clapTrap.takeDamage(10);
	clapTrap.attack("Wobble");
	clapTrap.beRepaired(1);
	clapTrap.takeDamage(1);
	return 0;
}
