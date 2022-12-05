#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		unsigned int	hp;
		unsigned int energy;
		unsigned int damage;
	
	public:
	ClapTrap(std::string);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName();
	int			getDamage();
};


#endif