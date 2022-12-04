#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
using std::cout;
using std::string;
using std::endl;

class Animal{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &ref);
	Animal operator = (const Animal &ref);
	string getType() const;
	virtual void makeSound() const;
protected:
	string type;
};

#endif
