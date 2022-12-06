#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:
		std::string name;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardgate();
		int get_hp();
		unsigned int get_energy();
};

#endif