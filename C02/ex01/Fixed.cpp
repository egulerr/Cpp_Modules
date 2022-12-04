#include "Fixed.hpp"
#include <cmath>
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

Fixed::Fixed(const int inp) {
	cout << "Int constructor called\n";
	this->_fixed_point = inp << _bits;
}

Fixed::Fixed(const float n) {
	this->_fixed_point = std::roundf(n * (1 << _bits));
	cout << "Float constructor called\n";
}

int Fixed::toInt() const {
	return this->_fixed_point >> _bits;
}

float Fixed::toFloat() const {
	return (float)this->_fixed_point / (1 << _bits);
}

std::ostream &operator << (std::ostream &out,const Fixed &f) {
	out << f.toFloat();
	return (out);
}

int Fixed::getRawBits() const {
	return (_fixed_point);
}

void Fixed::setRawBits(const int raw) {
	_fixed_point = raw;
}
