#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
using std::cout;
using std::string;

class Fixed{
public:
	//orthodox form
	Fixed ();
	Fixed (const Fixed &);
	Fixed & operator = (const Fixed &);
	~Fixed();
	//convert (int or float) to fixed-point
	Fixed (const float);
	Fixed (const int);
	//convert (fixed-point) to int or float
	float toFloat(void) const;
	int toInt(void) const;
	//getter setter
	int getRawBits() const;
	void setRawBits(int const);
	//comparison operator overloading
	bool operator == (const Fixed &) const;
	bool operator != (const Fixed &) const;
	bool operator > (const Fixed &) const;
	bool operator < (const Fixed &) const;
	bool operator >= (const Fixed &) const;
	bool operator <= (const Fixed &) const;
	//arithmetic operator overloading
	Fixed operator + (const Fixed &) const;
	Fixed operator - (const Fixed &) const;
	Fixed operator * (const Fixed &) const;
	Fixed operator / (const Fixed &) const;
	//increment/decrement operator overloading
	Fixed& operator ++ ();
	Fixed operator ++ (int);
	Fixed& operator -- ();
	Fixed operator -- (int);
	//max min overload with const
	const Fixed static &min(Fixed const &f1, Fixed const &f2);
	const Fixed static &max(Fixed const &, Fixed const &);
	//max min overload
	Fixed static &min(Fixed &f1, Fixed &f2);
	Fixed static &max(Fixed &f1, Fixed &f2);
private:
	int					_fixed_point;
	static const int	_bits = 8;
};


std::ostream& operator << (std::ostream &,const Fixed &);

#endif
