#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string);
	~HumanB(void);
	void	attack(void) const;
	void	setWeapon(Weapon&);
private:
	Weapon		*weapon;
	std::string	name;
};
