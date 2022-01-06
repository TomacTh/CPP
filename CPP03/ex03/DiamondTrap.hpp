#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	//using ScavTrap::attack;   no need to tell explicitly;
	DiamondTrap(void);
	DiamondTrap(DiamondTrap const &);
	DiamondTrap(std::string);
	virtual ~DiamondTrap(void);
	DiamondTrap &	operator=(DiamondTrap const &);
	//DIAMONDTRAP members functionS
	void		whoamI(void) const;
	std::string	getdiamondname(void) const;
private:
	std::string		_name;
};

