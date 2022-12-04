#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
using std::cout;
using std::string;
using std::endl;

class WrongAnimal{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &ref);
		WrongAnimal operator = (const WrongAnimal &ref);
		string getType() const;
		void makeSound() const;
	protected:
		string type;
};

#endif
