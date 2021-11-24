#pragma once
#include <iostream>

class	Zombie 
{
public:
	Zombie(std::string);
	~Zombie(void);
	void	announce(void) const;

private:
	std::string	name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

