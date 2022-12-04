#include "Fixed.hpp"
#include <cmath>
Fixed::Fixed() {
	_fixed_point = 0;
}

Fixed::Fixed (const Fixed &f)
{
	*this = f;
}

Fixed &Fixed::operator = (const Fixed &f) {
	this->_fixed_point = f.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int inp) {
	this->_fixed_point = inp << _bits;
}

Fixed::Fixed(const float n) {
	this->_fixed_point = std::roundf(n * (1 << _bits));
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

bool Fixed::operator == (const Fixed &f) const{
	return this->_fixed_point == f._fixed_point;
}

bool Fixed::operator != (const Fixed &f) const {
	return this->_fixed_point != f._fixed_point;
}

bool Fixed::operator > (const Fixed &f) const {
	return this->_fixed_point > f._fixed_point;
}

bool Fixed::operator<(const Fixed &f) const {
	return this->_fixed_point < f._fixed_point;
}

bool Fixed::operator>=(const Fixed &f) const {
	return this->_fixed_point >= f._fixed_point;
}

bool Fixed::operator <= (const Fixed &f) const{
	return this->_fixed_point <= f._fixed_point;
}

Fixed Fixed::operator+(const Fixed &f) const {
	Fixed res;

	res._fixed_point = (this->_fixed_point + f._fixed_point);
	return (res);
}

Fixed Fixed::operator-(const Fixed &f) const {
	Fixed res;

	res._fixed_point = (this->_fixed_point + f._fixed_point);
	return (res);
}

Fixed Fixed::operator*(const Fixed &f) const {
	Fixed res(this->toFloat() * f.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed &f) const {
	Fixed res(this->toFloat() / f.toFloat());
	return (res);
}

Fixed& Fixed::operator++() {
	++this->_fixed_point;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);

	tmp._fixed_point = this->_fixed_point++;
	return (tmp);
}

Fixed &Fixed::operator--() {
	--this->_fixed_point;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);

	tmp._fixed_point = this->_fixed_point--;
	return (tmp);
}

const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2){
	if (f1._fixed_point < f2._fixed_point)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2){
	if (f1._fixed_point > f2._fixed_point)
		return (f1);
	else
		return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2){
	if (f1._fixed_point < f2._fixed_point)
		return (f1);
	else
		return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2){
	if (f1._fixed_point > f2._fixed_point)
		return (f1);
	else
		return (f2);
}