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
	Fixed	operator+(Fixed const &) const;
	Fixed	operator-(Fixed const &) const;
	Fixed	operator*(Fixed const &) const;
	Fixed	operator/(Fixed const &) const;

	bool	operator>(Fixed const &) const;
	bool	operator<(Fixed const &) const;
	bool	operator>=(Fixed const &) const;
	bool	operator<=(Fixed const &) const;
	bool	operator==(Fixed const &) const;
	bool	operator!=(Fixed const &) const;
	
	Fixed 	operator++(int);
	Fixed & operator++(void);
	Fixed 	operator--(int);
	Fixed & operator--(void); 
	
	int		getRawBits(void) const; 
	void	setRawBits(const int);
	
	int 	toInt( void ) const;
	float	toFloat( void ) const;
	
	static Fixed &	max(Fixed &, Fixed &);
	static Fixed &	min(Fixed &, Fixed &);
	
	static Fixed const &	max(Fixed const &, Fixed const &);
	static Fixed const &	min(Fixed const &, Fixed const &);

private:
	static int const	_fractionnal_bits;
	int					_value;
};

std::ostream &	operator<<(std::ostream & out,Fixed const & rhs);
