#pragma once
#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &);
	~Fixed(void);
	Fixed &	operator=(Fixed const &);
	int	getRawBits(void) const;
	void	setRawBits(int const);	
private:
	static const int	fractionnal_bits;
	int					value;
};
