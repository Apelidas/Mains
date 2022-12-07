#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain *mind;

	public:
		Cat();
		virtual ~Cat();
		virtual void makeSound();
		void think();
};


#endif