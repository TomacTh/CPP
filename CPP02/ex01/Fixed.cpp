#include "Fixed.hpp"

Fixed::Fixed(void):_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const integer):_value(integer << _fractionnal_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const flt):_value((int)roundf(flt * (float)256))
{
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractionnal_bits);
}

float	Fixed::toFloat(void) const
{
	return (float)((float)_value / (float)256);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		_value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int const	Fixed::_fractionnal_bits = 8;

std::ostream &	operator<<(std::ostream & o,Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
