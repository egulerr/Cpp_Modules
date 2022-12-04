#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &ref);
	WrongCat operator = (const WrongCat &ref);
	string getType() const;
	void makeSound() const;
};
#endif
