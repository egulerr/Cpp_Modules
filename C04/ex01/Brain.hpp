#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::string;

class Brain{
public:
	Brain();
	~Brain();
	Brain(const Brain &ref);
	Brain &operator = (const Brain &ref);
private:
	string ideas[100];
};
#endif
