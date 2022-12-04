#include "ClapTrap.hpp"

int main(){
	ClapTrap eyup("Eyup", 100, 2, 35);
	ClapTrap mert("Mert");
	ClapTrap burak;

	mert.setHealth(150);
	mert.setEnergy(5);
	mert.setDamage(50);
	mert.takeDamage(149);

	eyup.attack("Burak");
	eyup.beRepaired(50);
	eyup.takeDamage(250);
}