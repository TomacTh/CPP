#pragma once
#include <iostream>

class Weapon
{
public:
	Weapon(std::string);
	~Weapon(void);
	std::string	getType(void);
	void		setType(std::string);
private:
	std::string	type;
};
