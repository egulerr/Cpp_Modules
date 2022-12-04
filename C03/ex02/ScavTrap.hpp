#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
	ScavTrap();
	ScavTrap(string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &ref);
	ScavTrap(string name, unsigned int health, unsigned int energy, unsigned int damage);
	ScavTrap& operator = (const ScavTrap &ref);

	void guardGate() const;
	void attack(const string &target);
};

#endif
