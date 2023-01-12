#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	//std::cout << "Ice Default Constructor" << std::endl;
}

Ice::Ice(Ice &copy): AMateria(copy.getType())
{
	//std::cout << "Ice Copy Constructor" << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << "*shoots an Ice Bolt at " << target.getName() << "*" << std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice);
}