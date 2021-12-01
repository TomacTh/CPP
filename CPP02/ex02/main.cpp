#include "Fixed.hpp"

int main(void) {
	//SUBJECT TEST
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	//MORE TEST
	std::cout << std::endl;
	Fixed divide(Fixed(10) / Fixed(2.5f));
	Fixed add(Fixed(5) + Fixed(10.25f));
	Fixed subtract(Fixed(40) - Fixed(39.5f));

	std::cout << "TEST DIVISION OVERLOAD(10 / 2.5): " << divide << std::endl;
	std::cout << "TEST ADDITION OVERLOAD(5 + 10.25): " << add << std::endl;
	std::cout << "TEST SUBTRACT OVERLOAD(40 - 39.5): " << subtract << std::endl;
	Fixed copy_divide(divide); //or copy_divide = divide
	if (copy_divide == divide)
		std::cout << "Copy divide: " << copy_divide << " is equal to divide: " << divide << std::endl;
	if (copy_divide < add)
		std::cout << "Copy divide: " << copy_divide << " is smaller than add: " << add << std::endl;
	if (copy_divide >= subtract)
		std::cout << "Copy divide: " << copy_divide << " is greater or equal to subtract: " << subtract << std::endl;
	if (copy_divide != b)
		std::cout << "Copy divide: " << copy_divide << " not equal to b: " << b << std::endl;
	std::cout << "pre decrement copy divide: " << copy_divide-- << std::endl;
	std::cout << "print now " << copy_divide << std::endl;
	std::cout << "post decrement copy divide: " << --copy_divide << std::endl;

	std::cout << "MIN BETWEEN copy divide and add: " << Fixed::min(copy_divide, add) << std::endl;
	std::cout << "MAX BETWEEN copy divide and add: " << Fixed::max(copy_divide, add) << std::endl;

	return (0);
}
