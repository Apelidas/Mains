#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *mind;
	public:
		Dog();
		virtual ~Dog();
		virtual void makeSound();
		void think();
};


#endif