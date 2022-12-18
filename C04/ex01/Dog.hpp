#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
private:
	Brain *brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &ref);
	Dog &operator = (const Dog &ref);
	string getType() const;
	void makeSound() const;
};

#endif
