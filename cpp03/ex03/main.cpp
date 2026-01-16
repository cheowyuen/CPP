#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	DiamondTrap diamond("Diamond");
	diamond.attack("Enemy");
	diamond.beRepaired(10);
	diamond.takeDamage(5);
	diamond.whoAmI();
	for (int i = 0; i < 60; i++) {
		 diamond.attack("Enemy");
	}
	diamond.beRepaired(5);
	return 0;
}
