#pragma once
#include <iostream>

class	Zombie 
{
public:
	Zombie(std::string);
	Zombie(void);
	~Zombie(void);
	void	announce(void) const;
	void	setname(std::string);

private:
	std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

