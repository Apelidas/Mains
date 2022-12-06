#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
}

Dog::~Dog()
{
}

void Dog::makeSound()
{
	std::cout << "Wuff Wuff!" << std::endl;
}