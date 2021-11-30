#include "Point.hpp"

Point::Point(void):x(0),y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(Point const & src)
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Point::~Point(void)
{
	std::cout << "Destructor called" << std::endl;
}

Point &	Point::operator=(Point const & rhs)
{	
	if (this != &rhs)
	{
		(Fixed)this->x = rhs.x;	
		(Fixed)this->y = rhs.y;
	}
	return (*this);
}

Fixed const	Point::getx(void) const
{
	return x;
}

Fixed const	Point::gety(void) const
{
	return y;
}

Point::Point(float const x_arg, float const y_arg):x(x_arg), y(y_arg)
{	
	std::cout << "Parametrical constructor called" << std::endl;
}
