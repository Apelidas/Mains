#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat-Default Constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "Miau! (Give me food)" << std::endl;
}