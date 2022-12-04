#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	cout << "Cat default constructor called." << endl;
}

Cat::~Cat() {
	cout << "Cat destructor called." << endl;
}

Cat::Cat(const Cat &ref) {
	*this = ref;
}

Cat Cat::operator=(const Cat &ref) {
	this->type = ref.type;
	return (*this);
}

string Cat::getType() const{
	return (this->type);
}

void Cat::makeSound() const{
	cout << getType() << ": Meooww" << endl;
}
