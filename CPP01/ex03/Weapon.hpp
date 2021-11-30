#pragma once
#include <iostream>

class Weapon
{
public:
	Weapon(std::string);
	~Weapon(void);
	std::string const &	getType(void) const;
	void		setType(std::string);
private:
	std::string	type;
};
