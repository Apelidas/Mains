#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	public:
		Cure();
		Cure(Cure &copy);
		virtual ~Cure() {}
		virtual void use(ICharacter& target);
		virtual Cure* clone() const;
};


#endif