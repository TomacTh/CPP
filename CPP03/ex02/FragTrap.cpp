#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	_name = "defaultFragTrap";
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string str) {
	_name = str;
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "Parametrical FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) {
	*this = src;
	std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
	if (this != &rhs)
	{
		_name = rhs.getname();
		_hitpoints = rhs.gethitpoints();
		_attackdamage = rhs.getattackdamage();
		_energypoints = rhs.gethitpoints();
	}
	return (*this);
}
//public function member
void	FragTrap::highFivesGuys(void) const
{
	std::cout << "( ⌒o⌒)人(⌒-⌒ )v" << std::endl;
}
