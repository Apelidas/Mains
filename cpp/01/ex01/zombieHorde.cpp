#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
	std::allocator<Zombie>	help;
	Zombie 					*out;

	out = help.allocate(N);
	for (int i = 0; i < N; i++)
	{
		help.construct(out + i, name);
	}
	return (out);
}

void Zombie::destroyHorde(int N)
{
	std::allocator<Zombie> help;

	for (int i = 0; i < N; i++)
	{
		help.destroy(this + i);
	}
	help.deallocate(this, N);
}