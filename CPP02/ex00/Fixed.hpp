#pragma once
#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &);
	~Fixed(void);
	Fixed &	operator=(Fixed const &);
	int		getRawBits(void) const;
	void	setRawBits(int const);
private:
	static int const	fractionnal_bits;
	int					value;
};
