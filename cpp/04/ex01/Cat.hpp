#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain *mind;

	public:
		Cat();
		Cat(Cat const &in);
		virtual ~Cat();
		virtual void makeSound();
		void think();
		Cat& operator=(Cat const &in);
};


#endif