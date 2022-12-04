#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	cout << "WrongAnimal default constructor called." << endl;
}
WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal destructor called." << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) {
	*this = ref;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal &ref) {
	this->type = ref.type;
	return (*this);
}

string WrongAnimal::getType() const{
	return (this->type);
}

void WrongAnimal::makeSound() const{
	cout << getType() <<": WrongAnimal sound" << endl;
}