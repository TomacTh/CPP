#include "FragTrap.hpp"

int main (void)
{
	FragTrap ftrap("FRAGMONSTER");

	std::cout << "\nshow specs:\n" << "HITPOINTS: " << ftrap.gethitpoints() <<
	"\nENERGYPOINTS: " << ftrap.getenergypoints()
	<< "\nATTACKDAMAGE: " << ftrap.getattackdamage() <<
	"\nNAME: " << ftrap.getname() << "\n\n";

	ftrap.attack("target");
	ftrap.beRepaired(18);
	ftrap.highFivesGuys();
	return (0);
}
