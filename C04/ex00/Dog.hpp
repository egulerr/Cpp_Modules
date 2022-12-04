#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
public:
	Dog();
	~Dog();
	Dog(const Dog &ref);
	Dog operator = (const Dog &ref);
	string getType() const;
	void makeSound() const;
};

#endif
