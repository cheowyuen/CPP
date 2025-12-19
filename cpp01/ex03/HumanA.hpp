#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string		name;
		Weapon			&weapon;

	public:
		HumanA(const std::string &_name, Weapon &_weapon);
		
		void attack() const;
};

#endif
