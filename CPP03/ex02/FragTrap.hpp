#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(FragTrap const &);
	FragTrap(std::string);
	virtual ~FragTrap(void);
	FragTrap &	operator=(FragTrap const &);
	//members function
	void	highFivesGuys(void) const;
};
