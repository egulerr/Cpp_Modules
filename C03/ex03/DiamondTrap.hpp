#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
public:
	DiamondTrap();
	DiamondTrap(string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &ref);
	DiamondTrap operator = (const DiamondTrap &ref);

private:
	string	name;
};

#endif
