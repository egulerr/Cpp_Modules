#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: virtual public ClapTrap{
public:
	FragTrap();
	FragTrap(string name);
	~FragTrap();
	FragTrap(const FragTrap &ref);
	FragTrap& operator = (const FragTrap &ref);
	FragTrap(string name, unsigned int health, unsigned int energy, unsigned int damage);

	void highFivesGuys();
};

#endif
