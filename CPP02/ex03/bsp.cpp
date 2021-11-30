#include  "Point.hpp"


Point	const vect(Point const a, Point const b)
{
	float x = a.getx().toFloat() - b.getx().toFloat();
	float y = b.gety().toFloat() - a.gety().toFloat();
	Point vect(x, y);
	return (vect);
}

float	const dot_multiply(Point const one, Point const two)
{
	float dot;

	dot = a.gety().toFloat() 
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point const ab = vect(a, b);
	Point const ap = vect(a, point);
	Point const bc = vect(b, c);
	Point const bp = vect(b, point);
	Point const ca = vect(c, a);
	Point const cp = vect(c, point);


}
