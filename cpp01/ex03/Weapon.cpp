#include "Weapon.hpp"

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(const std::string& _type)
{
	type = _type;
}
