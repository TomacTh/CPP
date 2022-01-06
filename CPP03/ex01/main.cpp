#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap strap("BIGONEscav");
	std::cout << "\nshow specs:\n" << "HITPOINTS: " << strap.gethitpoints() << "\nENERGYPOINTS: " << strap.getenergypoints() << "\nATTACKDAMAGE: " << strap.getattackdamage() << "\nNAME: " << strap.getname() << "\n\n";
	strap.attack("target");
	strap.beRepaired(18);
	strap.guardGate();
	return (0);
}
