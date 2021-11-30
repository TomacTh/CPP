#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &);
	Fixed(int const);
	Fixed(float const);
	~Fixed(void);
	Fixed &	operator=(Fixed const &);
	int		getRawBits(void) const;
	void	setRawBits(const int);
	int 	toInt( void ) const;
	float	toFloat( void ) const;
private:
	static int const	_fractionnal_bits;
	int					_value;
};

std::ostream &	operator<<(std::ostream & out,Fixed const & rhs);
