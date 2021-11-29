#include "Zombie.hpp"

Zombie::Zombie(std::string str):name(str)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie destructor called on " << name << std::endl;
}

void	Zombie::announce(void) const
{
	std::string str;

	str = "<";
	str += name;
	str += ">";
	str += "  BraiiiiiiinnnzzzZ...";
	std::cout << str << std::endl;
}
