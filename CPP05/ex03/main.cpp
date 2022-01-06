#include "Intern.hpp"

int main (void)
{
	Intern student;
	Bureaucrat boss("boss", 1);

	Form *form = student.makeForm("not know form", "specialtarget");
	std::cout << "\n\n";

	form = student.makeForm("presidential pardon", "starget");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	std::cout << "\n\n";

	form = student.makeForm("robotomy request", "starget");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	std::cout << "\n\n";

	form = student.makeForm("shrubbery creation", "starget");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	return (0);
}
