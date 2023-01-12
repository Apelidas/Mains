#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "New ClapTrap " << name << " created" << std::endl;
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
	this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " got scrapped for spare parts" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "ClapTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->damage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "ClapTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name << " received " << amount << " points of Damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0 || this->energy <= 0)
	{
		std::cout << "ClapTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->energy--;
	if (this->hp < 10)
	{
		this->hp += amount;
		std::cout <<  "ClapTrap " << this->name << "got repaired by " << amount << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " looks splendid" << std::endl;
}

std::string ClapTrap::getName()
{
	return (this->name);
}

int ClapTrap::getDamage()
{
	return (this->damage);
}