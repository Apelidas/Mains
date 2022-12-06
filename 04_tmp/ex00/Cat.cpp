#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
}

Cat::~Cat()
{
}

void Cat::makeSound()
{
	std::cout << "Miau! (Give me food)" << std::endl;
}