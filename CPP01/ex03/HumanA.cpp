#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& weaponarg):weapon(weaponarg), name(str)
{
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor called" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
