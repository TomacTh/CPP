#include "DiamondTrap.hpp"

//CONSTRUTOR DESTRUCOR
DiamondTrap::DiamondTrap(void):_name("DefaultDiamondTrap") {
	ClapTrap::_name = _name + "_clap_name";
	_energypoints = this->ScavTrap::default_values[0];
	_hitpoints = default_values[1];
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called"  << std::endl;
}

DiamondTrap::DiamondTrap(std::string str):_name(str) {
	ClapTrap::_name = _name + "_clap_name";
	_energypoints = default_values[0];
	_hitpoints = default_values[1];
	std::cout << ClapTrap::_name  + "\nDiamondTrap parametrical constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) {
	*this = src;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs) {
	if (this != &rhs)
	{
		ClapTrap::_name = rhs.getname();
		_hitpoints = rhs.gethitpoints();
		_attackdamage = rhs.getattackdamage();
		_energypoints = rhs.gethitpoints();
		_name = rhs.getdiamondname();
	}
	return (*this);
}

//members function AND ACCESSORS
std::string	DiamondTrap::getdiamondname(void) const {
	return (_name);
}

void	DiamondTrap::whoamI(void) const {
	std::cout << "CLAPTRAP_NAME: " << ClapTrap::_name << "\nNAME: " << _name;
}
