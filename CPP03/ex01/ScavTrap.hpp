#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(ScavTrap const &);
	ScavTrap(std::string);
	virtual ~ScavTrap(void);
	ScavTrap &	operator=(ScavTrap const &);
	//members function
	void	guardGate(void) const;
	void	attack(std::string const &) const;
};
