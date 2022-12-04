#include "Fixed.hpp"

Fixed::Fixed() {
	_fixed_point = 0;
	cout << "Default constructor called\n";
}

Fixed::Fixed (const Fixed &f)
{
	cout << "Copy constructor called\n";
	*this = f;
}

Fixed &Fixed::operator = (const Fixed &f) {
	cout << "Copy assignment operator called\n";
	this->_fixed_point = f.getRawBits();
	return (*this);
}
Fixed::~Fixed() {
	cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
	cout << "getRawBits member function called\n";
	return (_fixed_point);
}

void Fixed::setRawBits(const int raw) {
	_fixed_point = raw;
}
