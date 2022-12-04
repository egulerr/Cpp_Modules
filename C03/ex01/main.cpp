#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	ClapTrap eyup("Eyup", 100, 2, 35);
	ScavTrap burak("Burak", 6123,5123,52);

	burak.attack("eyup");
	eyup.attack("burak");
	burak.beRepaired(25);
	burak.takeDamage(122);
}