#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

	this->name = "ClapTrap";
	this->health = 10;
	this->energy = 10;
	this->damage = 0;
	cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	cout << "1 parameter constructor called." << std::endl;
	this->name = name;
	this->health = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &cl) {
	*this = cl;
	cout << "Copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cl) {
	cout << "Operator overloading called." << std::endl;
	this->damage = cl.damage;
	this->energy = cl.energy;
	this->health = cl.energy;
	this->name = cl.name;
	return (*this);
}

ClapTrap::~ClapTrap() {
	cout << "Destructor called.\n";
}

ClapTrap::ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int damage) {
	this->name = name;
	this->health = health;
	this->energy = energy;
	this->damage = damage;
	cout << "4 parameter constructor called." << std::endl;
}

void ClapTrap::setName(std::string name) {
	this->name = name;
}

void ClapTrap::setHealth(unsigned int health) {
	this->health = health;
}

void ClapTrap::setEnergy(unsigned int energy) {
	this->energy = energy;
}

void ClapTrap::setDamage(unsigned int damage) {
	this->damage = damage;
}

string ClapTrap::getName() {
	return (this->name);
}

unsigned int ClapTrap::getHealth() {
	return (this->health);
}

unsigned int ClapTrap::getEnergy() {
	return (this->energy);
}

unsigned int ClapTrap::getDamage() {
	return (this->damage);
}

void ClapTrap::attack(const std::string &target) {
	if (this->energy >= 1) {
		cout << "\033[1;31mClapTrap: " << this->name << " attacks " << target <<
		", causing " << this->damage << " points of damage! - ";
		this->energy -= 1;
		cout << "You used 1 energy.\033[0m" << std::endl;
	}
	else
		cout << "\033[1;31mYou can't attack. Because your energy below \"1\".\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->health < 1)
		cout << "\033[1;31mYou can't attack. Because your health at below \"1\".\033[0m" << std::endl;
	else{
		if (amount >= this->health) {
			cout <<"\033[1;31m" << this->getName() << " took " << amount << " damage. " << this->getName() <<" died.\033[0m" << std::endl;
			amount = this->health;
		}
		else
			cout << "\033[1;31m" << this->getName() << " took " << amount << " damage.\033[0m" << std::endl;
		this->health -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (this->energy >= 1) {
		cout << "\033[1;31mOld health: " << this->health;
		this->health += amount;
		cout << " - New health: " << this->health;
		this->energy -= 1;
		cout << " - You used 1 energy.\033[0m" << std::endl;
	}
	else
		cout << "\033[1;31mYou can't repair. Because your energy below \"1\".\033[0m" <<std::endl;
}