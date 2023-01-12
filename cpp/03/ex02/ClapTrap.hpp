#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int	hp;
		unsigned int	energy;
		unsigned int	damage;
	
	public:
	ClapTrap();
	ClapTrap(std::string);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName();
	int			getDamage();
};


#endif