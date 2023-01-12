#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal-Default Constructor" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal Constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

std::string Animal::getType()
{
	return (this->type);
}

void Animal::makeSound()
{
	std::cout << "I am an Animal!" << std::endl;
}

Animal& Animal::operator=(Animal const &in)
{
	this->type = in.type;
	return (*this);
}

void Animal::setType(std::string type)
{
	this->type = type;
}