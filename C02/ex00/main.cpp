#include "Fixed.hpp"

int main(){
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	cout << a.getRawBits() << "\n";
	cout << b.getRawBits() << "\n";
	cout << c.getRawBits() << "\n";
}