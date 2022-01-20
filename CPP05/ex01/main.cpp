#include "Bureaucrat.hpp"

int main (void)
{
	std::cout << "\033[32m";
	Bureaucrat first("first", 42);
	Form		valid("valid", 41, 42);
	std::cout << "\033[m";

	first.signForm(valid);
	try
	{
		Form invalid("invaid", -1, 151);
	}
	catch(std::exception &e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[m";
	}
	try
	{
		first.decrementGrade();
		first.signForm(valid);
		valid.beSigned(first);
	}
	catch(std::exception &e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[m";
	}
	std::cout << valid << std::endl;
	std::cout << first << std::endl;
	return (0);
}
