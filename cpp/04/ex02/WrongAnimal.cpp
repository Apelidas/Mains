#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
}

WrongAnimal::~WrongAnimal()
{
}

std::string WrongAnimal::getType()
{
	return (this->type);
}

void WrongAnimal::makeSound()
{
	std::cout << "I am a WrongAnimal!" << std::endl;
}