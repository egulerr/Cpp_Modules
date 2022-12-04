#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon{
public:
	Weapon(std::string type);
	std::string const &getType();
	void setType(std::string type);
private:
	std::string _type;
};

#endif