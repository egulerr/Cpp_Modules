#include <iostream>
class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	void setName(std::string _name);
	std::string getName();
	void announce(void);
	~Zombie();
private:
	std::string name;
};

void randomChump (std::string _name);
Zombie *newZombie(std::string _name);
