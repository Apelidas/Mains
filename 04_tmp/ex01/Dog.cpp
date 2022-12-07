#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->mind = new Brain();
	std::cout << "Dog-Default Constructor" << std::endl;
}

Dog::~Dog()
{
	delete this->mind;
	std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "Wuff Wuff!" << std::endl;
}

void Dog::think()
{
	std::cout << this->mind->get_idea() << std::endl;
}