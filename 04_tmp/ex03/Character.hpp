#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		Character();
		Character(std::string name);
		Character(Character const &copy);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		AMateria *getInv(int idx) const;
		Character &operator=(Character const &copy);

};

#endif