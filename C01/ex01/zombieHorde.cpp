#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newZom = new Zombie[N];
	int i;

	i = 0;
	while (i < N)
	{
		newZom[i].setName(name);
		i++;
	}
	return (newZom);
}