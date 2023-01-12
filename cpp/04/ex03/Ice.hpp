#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice();
		Ice(Ice &copy);
		virtual ~Ice() {}
		virtual void use(ICharacter& target);
		virtual Ice* clone() const;
};


#endif