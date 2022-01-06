#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap cltrap("newclaptrap");
	std::cout << "\nshow specs:\n" << "HITPOINTS: " << cltrap.gethitpoints() << "\nENERGYPOINTS: " << cltrap.getenergypoints() << "\nATTACKDAMAGE: " << cltrap.getattackdamage() << "\nNAME: " << cltrap.getname() << "\n\n";
	cltrap.attack("target");
	cltrap.takeDamage(5);
	cltrap.beRepaired(5);
	return (0);
}
