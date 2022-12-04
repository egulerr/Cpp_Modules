#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "FragTrap";
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->name = name;
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	cout << "FragTrap 1 parameter constructor called." << std::endl;
}

FragTrap::~FragTrap() {
	cout << "FragTrap destructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref){
	cout << "FragTrap copy constructor called." << std::endl;
	*this = ref;
}

FragTrap &FragTrap::operator=(const FragTrap &ref) {
	this->name = ref.name;
	this->health = ref.health;
	this->energy = ref.energy;
	this->damage = ref.damage;
	cout << "FragTrap operator overloading called." << std::endl;
	return (*this);
}

FragTrap::FragTrap(std::string name, unsigned int health, unsigned int energy, unsigned int damage) {
	this->name = name;
	this->health = health;
	this->energy = energy;
	this->damage = damage;
	cout << "FragTrap 4 parameter constructor called." << std::endl;
}

void FragTrap::highFivesGuys() {
	if (this->health >= 1)
		cout << "\033[1;31m" << this->name << ": high fives guys!\033[0m" << std::endl;
	else
		cout << "\033[1;31m" << this->name << " can't high five. Because " << this->name << " died.\033[0m" << std::endl;
}