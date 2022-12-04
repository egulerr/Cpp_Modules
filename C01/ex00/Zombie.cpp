#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::Zombie() {
	this->name = "Default";
}

void Zombie::setName(std::string _name){
	name = _name;
}
std::string Zombie::getName(){
	return (name);
}
void Zombie::announce(void){
	std::cout << getName() << ": BraiiiiiinnnnzzzzZ..." <<std::endl;
}
Zombie::~Zombie() {
	std::cout << "The zombie named \"" << getName() << "\" has been deleted.\n";
}
