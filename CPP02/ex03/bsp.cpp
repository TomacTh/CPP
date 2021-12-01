#include  "Point.hpp"

Point	const vect(Point const a, Point const b)
{
	float x = b.getx().toFloat() - a.getx().toFloat();
	float y = b.gety().toFloat() - a.gety().toFloat();
	Point vect(x, y);
	return (vect);
}

float	cross_product(Point const one, Point const two)
{
	float dot;

	dot = one.getx().toFloat() * two.getx().toFloat() + one.gety().toFloat() * two.gety().toFloat();
	return (dot);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point const ab = vect(a, b);
	Point const ap = vect(a, point);
	Point const bc = vect(b, c);
	Point const bp = vect(b, point);
	Point const ca = vect(c, a);
	Point const cp = vect(c, point);

	float const abap = cross_product(ab, ap);
	float const bcbp = cross_product(bc, bp);
	float const cacp = cross_product(ca, cp);

	if ((abap > 0 && bcbp > 0 && cacp > 0) || (abap < 0 && bcbp < 0 && cacp < 0))
		return (true);
	else
		return (false);
}
