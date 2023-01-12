#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog-Default Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "Wuff Wuff!" << std::endl;
}