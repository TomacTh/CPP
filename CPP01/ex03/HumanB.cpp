#include "HumanB.hpp"

HumanB::HumanB(std::string str):weapon(nullptr), name(str)
{
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::attack(void) const
{	
	if (!weapon)
		std::cout << name << " has no weapon, cannot attack" << std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponarg)
{
	this->weapon = &weaponarg;
}
