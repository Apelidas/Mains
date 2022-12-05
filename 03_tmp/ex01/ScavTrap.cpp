#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "New ScavTrap " << name << " created" << std::endl;
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " got scrapped for spare parts" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "ScavTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "ScavTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->damage << " points of damage" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "ScavTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->hp -= amount;
	std::cout << "ScavTrap " << this->name << " received " << amount << " points of Damage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0 || this->energy <= 0)
	{
		std::cout << "ScavTrap " << this->name << " doesn´t react" << std::endl;
		return ;
	}
	this->energy--;
	if (this->hp < 10)
	{
		this->hp += amount;
		std::cout <<  "ScavTrap " << this->name << "got repaired by " << amount << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " looks splendid" << std::endl;
}

void ScavTrap::guardgate()
{
	std::cout << "YOU SHALL NOT PASS... this gate" << std::endl;
}


