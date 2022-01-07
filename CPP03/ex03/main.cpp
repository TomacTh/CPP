#include "DiamondTrap.hpp"

int main (void)
{
	DiamondTrap dtrap("DIAMONDMONSTER");

	std::cout << "\nSHOW SPECS:\nHITPOINTS: " << dtrap.gethitpoints()
	<< "\nENERGYPOINTS: " << dtrap.getenergypoints() << "\nATTACKDAMAGE: "
	<< dtrap.getattackdamage() << "\nNAME: " << dtrap.getdiamondname()
	<< "\nCLAP_NAME: " + dtrap.getname() << "\n\n";

	//claptrapfunc
	dtrap.attack("target");
	dtrap.beRepaired(18);
	//scav and frag functions
	dtrap.highFivesGuys();
	dtrap.guardGate();
	//diamondtrap func
	dtrap.whoamI();
	return (0);
}
