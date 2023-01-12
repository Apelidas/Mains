#include "Zombie.hpp"

void TestZombie()
{
	Zombie blub("blub");
	void *ptr;
	Zombie *secund;
	Zombie *first = blub.newZombie("Programmer");

	first->announce();
	delete first;
	std::cout << "_______________Test-Standard\n";
	first = blub.newZombie("Betsy");
	secund = blub.newZombie("SchwibbelSchwabbel");
	first->announce();
	secund->announce();
	std::cout << "_______________Test-Pointer\n";
	ptr = secund;
	secund = first;
	first = (Zombie *) ptr;
	first->announce();
	secund->announce();
	std::cout << "_______________\n";
	delete first;
	delete secund;
}

void testrandom()
{
	Zombie help("blubb");

	help.randomChump("Schwibbel");
	help.randomChump("Schwabbel");
}

int main()
{
	TestZombie();
	std::cout << "__________________________next\n";
	testrandom();
}