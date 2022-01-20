#include "ClapTrap.hpp"

void show_specs(ClapTrap &clap)
{
	std::cout << "\nshow specs:\n" << "HITPOINTS: " << clap.gethitpoints() << "\nENERGYPOINTS: " << clap.getenergypoints() << "\nATTACKDAMAGE: " << clap.getattackdamage() << "\nNAME: " << clap.getname() << "\n\n";
}

int main (void)
{
	ClapTrap cltrap("newclaptrap");
	ClapTrap target("Targetclaptrap");
	show_specs(cltrap);
	cltrap.attack("target");
	target.takeDamage(5);
	cltrap.takeDamage(5);
	cltrap.beRepaired(5);
	show_specs(cltrap);
	show_specs(target);
	return (0);
}
