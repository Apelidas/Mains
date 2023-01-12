#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "New FragTrap " << name << " created" << std::endl;
	this->name = name;
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " got scrapped for spare parts" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "FragTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "FragTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->damage << " points of damage" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "FragTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->hp -= amount;
	std::cout << "FragTrap " << this->name << " received " << amount << " points of Damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0 || this->energy <= 0)
	{
		std::cout << "FragTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->energy--;
	if (this->hp < 100)
	{
		this->hp += amount;
		std::cout <<  "FragTrap " << this->name << "got repaired by " << amount << std::endl;
	}
	else
		std::cout << "FragTrap " << this->name << " looks splendid" << std::endl;
}


void FragTrap::highFiveGuys()
{
	std::cout << "I love you Guys!" << std::endl << "Give me a High five" << std::endl;
}