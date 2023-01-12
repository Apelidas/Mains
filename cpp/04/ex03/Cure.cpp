#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	//std::cout << "Cure Default Constructor" << std::endl;
}

Cure::Cure(Cure &copy): AMateria(copy.getType())
{
	//std::cout << "Cure Copy Constructor" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "*heals " << target.getName() << "'s wounds" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure);
}

