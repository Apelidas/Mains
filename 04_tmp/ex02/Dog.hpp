#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *mind;
	public:
		Dog();
		Dog(Dog const &in);
		virtual ~Dog();
		virtual void makeSound() const;
		void think();
		Dog& operator=(Dog const &in);
};


#endif