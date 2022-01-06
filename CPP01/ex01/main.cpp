#include "Zombie.hpp"

int	main(void)
{
	Zombie*	horde;

 	horde = zombieHorde(0, "null");
	horde = zombieHorde(-1, "neg");
	horde = zombieHorde(10, "tenzombies");
	for(int i = 0; i < 10; ++i)
	{
		std::cout << i << " ";
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
