#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
private:
	Brain *brain;
public:
	Cat();
	~Cat();
	Cat(const Cat &ref);
	Cat operator = (const Cat &ref);
	string getType() const;
	void makeSound()const;
};

#endif
