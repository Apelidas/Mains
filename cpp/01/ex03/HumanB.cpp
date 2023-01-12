#include "HumanB.hpp"

void HumanB::attack()
{
	if (!this->thing)
	{
		std::cout << this->name << " attacks with their \"thing\"" << "\n";
	}
	else
		std::cout << this->name << " attacks with their " << this->thing->get_type() << "\n";
}

void HumanB::get_weapon(Weapon &thing)
{
	this->thing = &thing;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
}