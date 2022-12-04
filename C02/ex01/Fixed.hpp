#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
using std::cout;
using std::string;

class Fixed{
public:
	Fixed ();
	Fixed (const Fixed &);
	Fixed & operator =(const Fixed &);
	~Fixed();
	Fixed (const float);
	Fixed (const int);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits() const;
	void setRawBits(int const);
private:
	int					_fixed_point;
	static const int	_bits = 8;
};
	std::ostream& operator << (std::ostream &,const Fixed &);

#endif
