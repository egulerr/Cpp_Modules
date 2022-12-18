#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
using std::string;
using std::cout;

class ClapTrap{
private:
	string			name;
	unsigned int	health;
	unsigned int	energy;
	unsigned int	damage;
public:
	//Orthodox form
	ClapTrap();
	ClapTrap(string name);
	ClapTrap (const ClapTrap &ref);
	ClapTrap(string name, unsigned int health, unsigned int energy, unsigned int damage);
	~ClapTrap();
	ClapTrap & operator = (const ClapTrap &ref);
	//setter
	void setName(string name);
	void setHealth(unsigned int health);
	void setEnergy(unsigned int energy);
	void setDamage(unsigned int damage);
	//getter
	string getName();
	unsigned int getHealth();
	unsigned int getEnergy();
	unsigned int getDamage();
	//-------
	void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif
