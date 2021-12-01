#include "Fixed.hpp"

Fixed::Fixed(void):_value(0)
{
	return ;
}

Fixed::Fixed(Fixed const & copy)
{
	*this = copy;
}

Fixed::Fixed(int const integer):_value(integer << _fractionnal_bits)
{
	return ;
}

Fixed::Fixed(float const flt):_value((int)roundf(flt * (float)256))
{
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}
//METHOD
int	Fixed::toInt(void) const
{
	return (_value >> _fractionnal_bits);
}

float	Fixed::toFloat(void) const
{
	return (float)((float)_value / (float)256);
}
//OVERLOAD BASIC OPERATION
Fixed &	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		_value = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	Fixed	el;

	el.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (el);
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	Fixed	el;

	el.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (el);
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	Fixed	el((this->toFloat() / rhs.toFloat()));
	return (el);
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	Fixed	el(this->toFloat() * rhs.toFloat());
	return (el);
}
//OVERLOAD INCREMENT AND DECREMENT
Fixed 	Fixed::operator++(int)
{
	Fixed copy(*this);

	this->_value++;
	return (copy);
}

Fixed &	Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed 	Fixed::operator--(int)
{
	Fixed copy(*this);

	this->_value--;
	return (copy);
}

Fixed &	Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}
//OVERLOAD OPERATOR BOOL
bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->getRawBits() > rhs.getRawBits() ? true : false);
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits() ? true : false);
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits() ? true : false);
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits() ? true : false);
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits() ? true : false);
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits() ? true : false);
}
//ACCESSORS
int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
//STATIC
int const	Fixed::_fractionnal_bits = 8;

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a > b ? a : b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b ? a : b);
}
//OVERLOAD OUTPUT
std::ostream &	operator<<(std::ostream & o,Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
