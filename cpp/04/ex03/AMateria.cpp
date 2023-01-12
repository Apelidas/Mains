#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	//std::cout << "AMateria Constructor" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

AMateria::AMateria(const AMateria &copy)
{
	this->type = copy.type;
}


void AMateria::use(ICharacter& target)
{
	(void) target;
}

AMateria& AMateria::operator=(AMateria &copy)
{
	this->type = copy.type;
	return (*this);
}
