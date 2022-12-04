#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	ClapTrap eyup("Eyup", 100, 2, 35);
	ScavTrap burak("Burak", 612,51,45);
	FragTrap mert("Mert", 35,45,55);

	mert.attack("Eyup");
	mert.highFivesGuys();
	mert.takeDamage(45);
	mert.highFivesGuys();
	burak.attack("eyup");
	eyup.attack("burak");
	burak.beRepaired(25);
	burak.takeDamage(122);
}