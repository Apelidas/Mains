#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
	Zombie *newZombie(std::string name);
	void randomChump( std::string name );

	Zombie(std::string name);
	~Zombie();

	void announce( void );
	private:
	std::string name;
};

#endif