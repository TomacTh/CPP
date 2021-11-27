#include "Zombie.hpp"

Zombie::Zombie(std::string str):name(str)
{
	std::cout << "Zombie constructor with string called" << std::endl;
}

Zombie::Zombie(void):name("default")
{
	std::cout << "Default zombie constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie destructor called on " << name << std::endl;
}

void	Zombie::setname(std::string str)
{
	this->name = str;
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
