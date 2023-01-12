#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <memory>
class Zombie
{
	public:
	Zombie	*zombieHorde(int N, std::string name);
	void	destroyHorde(int N);
	Zombie(std::string name);
	~Zombie();

	void announce( void );
	private:
	std::string name;
};

#endif