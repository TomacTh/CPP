#include "Intern.hpp"

Form	*Intern::makeForm(std::string name, std::string target) const{
	std::string const	tab[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	Form	*(Intern::*func_tab[3])(std::string) const = {&Intern::returnRobotomyRequest, &Intern::returnShrubbery, &Intern::returnPresidential};

	int i;
	for (i = 0; i < 3; i++)
	{
		if (!tab[i].compare(name))
			break;
	}
	switch (i)
	{
		case (3):
			std::cerr << "Intern cannot create" << name << " form cause it doesn't know it\n";
			return (NULL);

		default:
			Form *form = (this->*func_tab[i])(target);
			std::cout << "Intern create " << form->getName() << std::endl;
			return (form);
	}
}

Intern const &	Intern::operator=(Intern const &) { return *this;}
