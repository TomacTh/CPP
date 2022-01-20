#include "Bureaucrat.hpp"

int main (void)
{
	std::cout << "\n\033[32m";
	Bureaucrat first;
	Bureaucrat second("second", 1);
	std::cout << "\033[m";
	std::cout << "\033[34mprinting : " << first << second << std::endl << "\033[m";

	try {	
		first.decrementGrade();
	}
	catch (const Bureaucrat::LOWException& e) {
		std::cerr << "\033[31m" << e.what() << "\033[m";
	}
	try {
		second.incrementGrade();
	}
	catch (const Bureaucrat::HIGHException& e) {
		std::cerr << "\033[31m" << e.what() << "\033[m";
	}
	try {
		Bureaucrat third("third", 4200);
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[m";
	}
	return (0);
}
