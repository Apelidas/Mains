#include "ClapTrap.hpp"

void test()
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

int main()
{
	test();
}