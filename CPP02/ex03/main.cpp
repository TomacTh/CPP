#include "Point.hpp"
//https://planetcalc.com/8108/
/*
|  .
|
| .   .
|_ _ _ _ _
*/

void	test_bsp(Point point)
{
	Point A(1, 1);
	Point B(2, 3);
	Point C(4, 1);

	if (bsp(A, B, C, point))
		std::cout << "Point inside" << std::endl;
	else
		std::cout << "Point outside" << std::endl;
}

int main(void)
{
	test_bsp(Point(2, 2)); //inside
	test_bsp(Point(2, 1)); //on edge
	test_bsp(Point(4, 4)); //outside
	test_bsp(Point(2, 3)); //on vertex
	test_bsp(Point(2.5f, 1.1f)); //inside
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << std::endl;
	Point A(7, 1.5);
	Point a_copy(A);
	std::cout << "a_copy (xfloat): " << a_copy.getx().toFloat() << " (yfloat): " << a_copy.getx().toFloat() << std::endl;
	Point a_assign = A;
	std::cout << "a_assign (xfloat): " << a_copy.getx().toFloat() << " (yfloat): " << a_copy.getx().toFloat() << std::endl;
	Point pointdefault;
	std::cout << "default: " << pointdefault.getx().toFloat() << " (yfloat): " << pointdefault.getx().toFloat() << std::endl;
}
