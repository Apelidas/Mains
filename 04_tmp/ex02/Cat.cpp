#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->mind = new Brain();
	std::cout << "Cat-Default Constructor" << std::endl;
}

Cat::Cat(Cat const &in)
{
	this->type = in.type;
	this->mind = new Brain();
	std::cout << "Cat-Copy Constructor" << std::endl;
}

Cat::~Cat()
{
	delete this->mind;
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau! (Give me food)" << std::endl;
}

void Cat::think()
{
	std::cout << this->mind->get_idea() << std::endl;
}

Cat& Cat::operator=(Cat const &in)
{
	this->type = in.type;
	return (*this);
}
