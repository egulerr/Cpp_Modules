#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	cout << "WrongCat default constructor called." << endl;
}

WrongCat::~WrongCat() {
	cout << "WrongCat destructor called." << endl;
}

WrongCat::WrongCat(const WrongCat &ref) {
	*this = ref;
}

WrongCat WrongCat::operator=(const WrongCat &ref) {
	this->type = ref.type;
	return (*this);
}

string WrongCat::getType() const{
	return (this->type);
}

void WrongCat::makeSound() const{
	cout << getType() << ": Meooww" << endl;
}
