#include "Zombie.hpp"

int main(void)
{
	Zombie* z;

	z = newZombie("Dr Edgar");
	z->announce();
	delete (z); 
	randomChump("Bucket Head");
	return (0);
}
