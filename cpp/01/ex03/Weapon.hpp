
#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		const std::string	&get_type();
		void			setType(std::string name);

		Weapon(std::string name);
		~Weapon();
};

#endif