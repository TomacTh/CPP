#pragma once
#include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(Point const &);
	Point(float const, float const);
	~Point(void);
	Point & operator=(Point const &);
	Fixed const getx(void) const;
	Fixed const gety(void) const;
private:
	Fixed const x;
	Fixed const	y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
