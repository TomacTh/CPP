#pragma once
#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &);
	Fixed(const int);
	Fixed(const float);
	~Fixed(void);
	Fixed &	operator=(const Fixed &);
	int	getRawBits(void) const;
	void	setRawBits(const int);	
private:
	static const int	fractionnal_bits;
	int					value;
};
