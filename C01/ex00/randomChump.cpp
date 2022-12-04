#include "Zombie.hpp"

void randomChump (std::string _name)
{
	Zombie zombie;
	zombie.setName(_name);
	zombie.announce();
}