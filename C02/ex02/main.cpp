#include "Fixed.hpp"

int main(){
	Fixed 	a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed	c(3);
	Fixed	d(4);
	Fixed	e;
	if (c < d)
		cout << "c object number is lower than d\n";
	e = c + d; //toplama
	cout << e << std::endl;
	cout << a << std::endl;
	cout << ++a << std::endl;
	cout << a << std::endl;
	cout << a++ << std::endl;
	cout << a << std::endl;
	cout << b << std::endl;
	cout << Fixed::max(a, b) << std::endl; // herhangi bir tanesi constsa gir parametre
	cout << Fixed::max(c, b) << std::endl; // constsuz olana gir parametre
}