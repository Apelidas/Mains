#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
		std::string name;

	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFiveGuys();
		int get_hp();
		unsigned int get_energy();
		unsigned int get_damage();

};

#endif