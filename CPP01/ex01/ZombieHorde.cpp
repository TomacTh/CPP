#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cerr << "Cannot create negative or empty Horde" << std::endl;
		return (nullptr);
	}
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].setname(name);
	return (horde);
}
