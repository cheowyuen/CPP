#include "Zombie.hpp"

int main()
{
	Zombie* z = newZombie("Dr Edgar");
	z->announce();
	delete z; 
	randomChump("Bucket Head");
	return 0;
}
