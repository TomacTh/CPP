#include "DiamondTrap.hpp"

int main (void)
{
	DiamondTrap dtrap("DIAMONDMONSTER");

	std::cout << "\nSHOW SPECS:\nHITPOINTS: " << dtrap.gethitpoints()
	<< "\nENERGYPOINTS: " << dtrap.getenergypoints() << "\nATTACKDAMAGE: "
	<< dtrap.getattackdamage() << "\nNAME: " << dtrap.getdiamondname()
	<< "\nCLAP_NAME: " + dtrap.getname() << "\n\n";

	dtrap.attack("target");
	dtrap.beRepaired(18);
	dtrap.highFivesGuys();
	dtrap.guardGate();
	return (0);
}
