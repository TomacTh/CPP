#include "Fixed.hpp"

Fixed::Fixed(void):_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & copy)
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed &	Fixed::operator=(const Fixed & rhs)
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

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

const int	Fixed::_fractionnal_bits = 8;
