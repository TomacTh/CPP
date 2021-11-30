#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie("normal");
	zombie.announce();

	Zombie *zomb = newZombie("new");
	zomb->announce();
	randomChump("randomone");
	std::cout << "the random is destroy just after created\n";
	delete zomb;
	return (0);
}
