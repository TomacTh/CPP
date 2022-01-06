#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void)
{
	std::string esc = "\033[m";
	std::cout << "\033[32m";

	//SHOULD HAVE NO EXCEPTION CAUSE (GRADE OK) SHRUBBERY TEST
	Bureaucrat first("first", 42);
	Form	*shruberry = new ShrubberyCreationForm("outfile");
	try
	{
		first.signForm(*shruberry);
		shruberry->execute(first);
	}
	catch(std::exception const &e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[m";
	}
	std::cout << esc;
	Bureaucrat crash("crash", 150);
	std::cout << "\033[31m";
	crash.executeForm(*shruberry);
	std::cout << esc;

	//ROBOTO TEST ONE OK ONE FAIL
	Form *roboto = new RobotomyRequestForm("robocop");

	first.signForm(*roboto);
	first.executeForm(*roboto);


	Bureaucrat dickhead("dickead", 150);
	std::cout << "\033[31m";
	dickhead.executeForm(*roboto);
	std::cout << "\033[m";
	//PRESIDENTIAL PARDON
	Form	*presidential = new PresidentialPardonForm("fugitive");
	std::cout << "\033[31m";
	dickhead.executeForm(*presidential);
	first.signForm(*presidential);
	std::cout << "\033[m";
	for (int i = 0; i < 40; i++)
		first.incrementGrade();
	first.signForm(*presidential);
	std::cout << "\033[32m";
	first.executeForm(*presidential);
	std::cout << "\033[m";

	std::cout << "\033[34m";
	std::cout << dickhead << first << crash << *shruberry << *presidential;
	std::cout << "\033[m";

	delete roboto;
	delete presidential;
	delete shruberry;

	return (0);
}
