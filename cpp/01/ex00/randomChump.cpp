#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie talker(name);
	talker.announce();
}