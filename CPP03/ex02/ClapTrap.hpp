#pragma once
#include <iostream>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(ClapTrap const &);
	ClapTrap(std::string);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const &);
	//accessors
	std::string	getname(void) const;
	int	gethitpoints(void) const;
	int	getenergypoints(void) const;
	int	getattackdamage(void) const;
	//members functions
	void	attack(std::string const &);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	std::string		_name;
	unsigned int				_hitpoints;
	unsigned int				_energypoints;
	unsigned int				_attackdamage;

};

