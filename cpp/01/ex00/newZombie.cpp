#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name)
{
	Zombie *walker = new Zombie(name);
	return (walker);
}