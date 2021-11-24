#include "Weapon.hpp"

Weapon::Weapon(std::string str):type(str)
{
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor called" << std::endl;
}

std::string	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string str)
{
	type = str;
}

