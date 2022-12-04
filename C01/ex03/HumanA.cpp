#include "HumanA.hpp"
HumanA::HumanA(std::string name, Weapon &weapon) {
	_name = name;
	_weapon = &weapon;
}

void HumanA::attack() {
	std::cout << _name << " attack with " << _weapon->getType() << "\n";
}