#include "Zombie.hpp"

Zombie *newZombie(std::string _name)
{
	Zombie *newZom = new Zombie(_name);
	return newZom;
}