#include "Zombie.hpp"

Zombie::Zombie() {
	this->_name = "Default";
}

void Zombie::setName(std::string name){
	_name = name;
}
std::string Zombie::getName(){
	return (_name);
}
void Zombie::announce(void){
	std::cout << getName() << ": BraiiiiiinnnnzzzzZ..." <<std::endl;
}
Zombie::~Zombie() {
	std::cout << "The zombie named \"" << getName() << "\" has been deleted.\n";
}
