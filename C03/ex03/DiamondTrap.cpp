#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	ClapTrap::name = "DiamondTrap";
	name += "_clap_name";
	FragTrap::health = 100;
	ScavTrap::energy = 50;
	FragTrap::damage = 30;
	cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	ClapTrap::name = name + "_clap_name";
	FragTrap::health = 100;
	ScavTrap::energy = 50;
	FragTrap::damage = 30;
	cout << "DiamondTrap 1 parameter constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) {
	*this = ref;
}

DiamondTrap DiamondTrap::operator=(const DiamondTrap &ref) {
	this->name = ref.name;
	this->health = ref.health;
	this->energy = ref.energy;
	this->damage = ref.damage;
	cout << "DiamondTrap operator overloading called." << std::endl;
	return (*this);
}

