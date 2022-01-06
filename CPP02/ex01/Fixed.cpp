#include "Fixed.hpp"

//CONSTRUCTORS DESTRUCTOR
Fixed::Fixed(void):_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const integer):_value(integer << _fractionnal_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const flt):_value((int)roundf(flt * (float)256))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor Called" << std::endl;
}

//OVERLOAD ASSIGN
Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		_value = rhs.getRawBits();
	return (*this);
}

//PUBLIC MEMBERS FUNCTIONS
int	Fixed::toInt(void) const
{
	return (_value >> _fractionnal_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)256);
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

int const	Fixed::_fractionnal_bits = 8;

//OVERLOAD STREAM
std::ostream &	operator<<(std::ostream & o,Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
