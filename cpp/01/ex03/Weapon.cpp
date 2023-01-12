#include "Weapon.hpp"

const std::string	&Weapon::get_type()
{
	std::string &ref = this->type;
	return (ref);
}

void	Weapon::setType(std::string name)
{
	this->type = name;
}

Weapon::Weapon(std::string name)
{
	this->type = name;
}

Weapon::~Weapon()
{
}
