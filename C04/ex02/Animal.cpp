#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	cout << "Animal default constructor called." << endl;
}
Animal::~Animal() {
	cout << "Animal destructor called." << endl;
}

Animal::Animal(const Animal &ref) {
	*this = ref;
}

Animal& Animal::operator=(const Animal &ref) {
	this->type = ref.type;
	return (*this);
}

string Animal::getType() const{
	return (this->type);
}

void Animal::makeSound() const{
	cout << getType() <<": Animal sound" << endl;
}