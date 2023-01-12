#include "HumanA.hpp"
#include "HumanB.hpp"

void TestWeapon()
{
	Weapon sword("sword");
	HumanA a("Kevin", sword);
	a.attack();
	sword.setType("Hellebarde");
	a.attack();
}

void TestHuman()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.get_weapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}

int main()
{
	TestWeapon();
	std::cout << "__________________________\n";
	TestHuman();

}