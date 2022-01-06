#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("defaultClapTrap"), _hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str):_name(str), _hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "Parametrical ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout << "Copy ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	if (this != &rhs)
	{
		_name = rhs.getname();
		_hitpoints = rhs.gethitpoints();
		_attackdamage = rhs.getattackdamage();
		_energypoints = rhs.getenergypoints();
	}
	return (*this);
}

//ACCESSORS GETTER

std::string ClapTrap::getname(void) const {
	return (_name);
}

int ClapTrap::gethitpoints(void) const {
	return (_hitpoints);
}

int ClapTrap::getenergypoints(void) const {
	return (_energypoints);
}

int ClapTrap::getattackdamage(void) const {
	return (_attackdamage);
}

//members function

void	ClapTrap::attack(std::string const & target) const{
	std::cout << _name + " attack " + target + ", causing " << this->getattackdamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitpoints -= amount;
	if (_hitpoints < 0)
		_hitpoints = 0;
	std::cout << _name + " takes damages, and loose " << amount << " hitpoints!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned amount) {
	_hitpoints += amount;
	std::cout << _name + " is repaired, and win " << amount << " hitpoints!" << std::endl;
}
