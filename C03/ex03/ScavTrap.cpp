#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	cout << "ScavTrap default constructor called." << std::endl;
	this->name = "ScavTrap";
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(std::string name) {
	cout << "ScavTrap 1 parameter constructor called" << std::endl;
	this->name = name;
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) {
	*this = ref;
}

ScavTrap::ScavTrap (std::string name, unsigned int health, unsigned int energy, unsigned int damage) {
	this->name = name;
	this->health = health;
	this->energy = energy;
	this->damage = damage;
	cout << "ScavTrap 4 parameter constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref) {
	this->name = ref.name;
	this->health = ref.health;
	this->energy = ref.energy;
	this->damage = ref.damage;
	cout << "ScavTrap operator overloading called." << std::endl;
	return (*this);
}

void ScavTrap::guardGate() const{
	cout << "ScavTrap is now in gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target){
	if (this->energy >= 1) {
		cout << "\033[1;31mScavTrap: " << this->name << " attacks " << target <<
			 ", causing " << this->damage << " points of damage! - ";
		this->energy -= 1;
		cout << "You used 1 energy.\033[0m" << std::endl;
	}
	else
		cout << "\033[1;31mYou can't attack. Because your energy below \"1\".\033[0m" << std::endl;
}
