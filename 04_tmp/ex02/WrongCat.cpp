#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound()
{
	std::cout << "Miau! (Give me food)" << std::endl;
}