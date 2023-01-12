#include "DiamondTrap.hpp"

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

void test_frag()
{
	FragTrap a("FR4G-TP");
	FragTrap b("Classic");

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.beRepaired(20);
	b.highFiveGuys();
}

void test_dia()
{
	DiamondTrap a("DI4M0ND-TP");
	DiamondTrap b("Pick");

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.beRepaired(20);
	b.highFiveGuys();
	b.guardgate();
	b.whoAmI();
}



int main()
{
	test_Clap();
	std::cout << std::endl;
	test_scav();
	std::cout << std::endl;
	test_frag();
	std::cout << std::endl;
	test_dia();
}