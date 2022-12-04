#include "Zombie.hpp"

int main()
{
	Zombie *obj;

	obj = newZombie("Eyup");
	obj->announce();
	randomChump("Burak");
	randomChump("Mert");
	randomChump("Hakan");
	delete obj;
}
