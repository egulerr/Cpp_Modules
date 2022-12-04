#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *zombies = zombieHorde(N, "Eyup");

	int i = 0;
	while (i < N)
	{
		zombies[i].announce();
		i++;
	}
	delete [] zombies;
}
