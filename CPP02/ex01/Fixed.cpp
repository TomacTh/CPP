#include "Fixed.hpp"

Fixed::Fixed(void):value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & src)
{	
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		value = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{	
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}


const int	Fixed::fractionnal_bits = 8;
