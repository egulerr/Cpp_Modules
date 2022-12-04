#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	brain = new Brain;
	cout << "Dog default constructor called." << endl;
}

Dog::~Dog() {
	delete brain;
	cout << "Dog Destructor called." << endl;
}

Dog::Dog(const Dog &ref) {
	*this = ref;
}

Dog Dog::operator=(const Dog &ref) {
	this->type = ref.type;
	brain = new Brain;
	*brain = *(ref.brain);
	return (*this);
}

string Dog::getType() const{
	return (this->type);
}

void Dog::makeSound() const{
	cout << getType() << ": Bark Bark" << endl;
}
