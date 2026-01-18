#include "FragTrap.hpp"

int main() {
	FragTrap fragTrap("Nibble");
	fragTrap.attack("Wobble");
	fragTrap.beRepaired(1);
	fragTrap.takeDamage(101);
	fragTrap.highFivesGuys();
	fragTrap.attack("Wobble");
	fragTrap.beRepaired(1);
	fragTrap.takeDamage(1);
	return 0;
}
