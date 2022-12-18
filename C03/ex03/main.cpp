#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
int main(){
	DiamondTrap hakan("Hakan");

	hakan.takeDamage(40);
	hakan.ScavTrap::attack("Burak");
}