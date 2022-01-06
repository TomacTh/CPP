#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(FragTrap const &);
	FragTrap(std::string);
	~FragTrap(void);
	FragTrap &	operator=(FragTrap const &);
	//members function
	void	highFivesGuys(void) const;
};
