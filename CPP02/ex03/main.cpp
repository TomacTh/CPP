#include "Point.hpp"

/*
|  .
|  i   o
| .   .
|_ _ _ _ _
*/

int main(void)
{
	Point A(1, 1);
	Point B(2, 3);
	Point C(4, 1);
	Point out(4, 2);
	Point in(2,2);

	if (bsp(A, B, C, out))
		std::cout << "out Point is inside the triangle" << std::endl;
	else if (bsp(A, B, C, in))
		std::cout << "in Point is inside the triangle" << std::endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << std::endl;
	Point a_copy(A);
	std::cout << "a_copy (xfloat): " << a_copy.getx().toFloat() << " (yfloat): " << a_copy.getx().toFloat() << std::endl;
	Point a_assign = A;
	std::cout << "a_assign (xfloat): " << a_copy.getx().toFloat() << " (yfloat): " << a_copy.getx().toFloat() << std::endl;
	Point pointdefault;
	std::cout << "default: " << pointdefault.getx().toFloat() << " (yfloat): " << pointdefault.getx().toFloat() << std::endl;
}
