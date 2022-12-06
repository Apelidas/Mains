#include "Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(std::string type)
{
	this->type = type;
}

Animal::~Animal()
{
}

std::string Animal::getType()
{
	return (this->type);
}

void Animal::makeSound()
{
	std::cout << "I am an Animal!" << std::endl;
}