#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->thing->get_type() << "\n";
}

HumanA::HumanA(std::string name, Weapon &thing)
{
	this->name = name;
	this->thing = &thing;
}

HumanA::~HumanA()
{
}