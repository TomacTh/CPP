#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA 
{
public:
	HumanA(std::string, Weapon&);
	~HumanA(void);
	void	attack(void) const;
private:
	Weapon		&weapon;
	std::string	name;
};
