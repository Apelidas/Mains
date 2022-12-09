#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

std::string Animal::getType()
{
	return (this->type);
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