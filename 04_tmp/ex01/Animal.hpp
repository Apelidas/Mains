#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		Brain *mind;

	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		std::string getType();
		void setType(std::string type);
		virtual void makeSound();
		Animal& operator=(Animal const &in);
};

#endif