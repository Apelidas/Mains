#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name): ScavTrap()
{
	std::cout << "New DiamondTrap " << name << " created" << std::endl;
	this->name = name;
	this->hp = this->FragTrap::get_hp();
	this->energy = this->ScavTrap::get_energy();
	this->damage =  this->FragTrap::get_damage();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " got scrapped for spare parts" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "DiamondTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->hp -= amount;
	std::cout << "DiamondTrap " << this->name << " received " << amount << " points of Damage" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0 || this->energy <= 0)
	{
		std::cout << "DiamondTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->energy--;
	if (this->hp < 100)
	{
		this->hp += amount;
		std::cout <<  "DiamondTrap " << this->name << "got repaired by " << amount << std::endl;
	}
	else
		std::cout << "DiamondTrap " << this->name << " looks splendid" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My ClapTrap Name:" <<this->ClapTrap::getName() << std::endl;
	std::cout << "My Name:" <<this->name << std::endl;
}
