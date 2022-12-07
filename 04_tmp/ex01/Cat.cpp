#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->mind = new Brain();
	std::cout << "Cat-Default Constructor" << std::endl;
}

Cat::~Cat()
{
	delete this->mind;
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "Miau! (Give me food)" << std::endl;
}

void Cat::think()
{
	std::cout << this->mind->get_idea() << std::endl;
}