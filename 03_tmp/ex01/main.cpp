#include "ScavTrap.hpp"

void test_Clap()
{
	ClapTrap a("pington");
	ClapTrap b("CL4P-TP");

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.beRepaired(2);
	b.takeDamage(4);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
}

void test_scav()
{
	ScavTrap a("SC4V-TP");
	ScavTrap b("RedBelly");

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.beRepaired(20);
	b.guardgate();
}


int main()
{
	//test_Clap();
	test_scav();
}