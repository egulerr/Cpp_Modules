#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
using std::string;
using std::cout;

class ClapTrap{
protected:
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
	//4 parameter constructor
	ClapTrap & operator = (const ClapTrap &ref);
	//setter
	void setName(string name);
	void setHealth(unsigned int health);
	void setEnergy(unsigned int energy);
	void setDamage(unsigned int damage);
	//getter
	string getName() const;
	unsigned int getHealth() const;
	unsigned int getEnergy() const;
	unsigned int getDamage() const;
	//-------
	void attack(const string &target) ;
	void takeDamage(unsigned int amount) ;
	void beRepaired(unsigned int amount) ;
};


#endif
