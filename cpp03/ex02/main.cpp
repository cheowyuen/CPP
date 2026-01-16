#include "FragTrap.hpp"

int main() {
	FragTrap fragTrap("Nibble");
	fragTrap.attack("Wobble");
	fragTrap.beRepaired(1);
	fragTrap.takeDamage(1);
	fragTrap.highFivesGuys();
	for (int i = 0; i < 9; i++) {
		fragTrap.attack("Wobble");
	}
	fragTrap.beRepaired(1);
	return 0;
}
