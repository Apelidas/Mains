#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		
		AMateria(std::string const & type);
		AMateria(AMateria const &copy);
		virtual ~AMateria() {}
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		AMateria& operator=(AMateria &copy);

};

#endif