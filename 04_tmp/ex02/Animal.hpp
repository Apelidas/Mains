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
		virtual ~Animal();
		std::string getType();
		void setType(std::string type);
		virtual void makeSound() const = 0;
		Animal& operator=(Animal const &in);
};

#endif