#include "Zombie.hpp"

void testHorde()
{
	Zombie	help("helper");
	Zombie	*horde;
	int		n = 12;

	horde = help.zombieHorde(n, "Das Fell");
	for(int i = 0; i < n;i++)
	{
		(horde + i)->announce();
	}
	horde->destroyHorde(n);
}

int main()
{
	testHorde();
}