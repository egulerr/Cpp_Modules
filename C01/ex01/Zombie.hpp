#include <iostream>
class Zombie
{
public:
	Zombie();
	void setName(std::string name);
	std::string getName();
	void announce(void);
	~Zombie();
private:
	std::string _name;
};

Zombie *zombieHorde(int N, std::string name);