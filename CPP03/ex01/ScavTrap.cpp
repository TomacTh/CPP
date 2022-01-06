#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("defaultScavTrap") {
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string str): ClapTrap(str) {
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
	std::cout << "Parametrical ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	*this = src;
	std::cout << "Copy ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
	if (this != &rhs)
	{
		_name = rhs.getname();
		_hitpoints = rhs.gethitpoints();
		_attackdamage = rhs.getattackdamage();
		_energypoints = rhs.gethitpoints();
	}
	return (*this);
}
//public members function
void	ScavTrap::guardGate(void) const
{
	std::cout << this->getname() << ": SCAVTRAP HAS ENTERED IN GATE MODE !!!!" << std::endl;
}

void	ScavTrap::attack(std::string const & target) const{
	std::cout << _name << " ScavATTACKS " << target << ", causing " << this->getattackdamage() << " points of damage!" << std::endl;
}
