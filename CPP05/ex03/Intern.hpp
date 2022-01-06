#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;

class Intern {
	public:
		Intern(){}
		Intern(Intern const & src){*this = src;}
		Intern const &	operator=(Intern const &);
		~Intern(){}
		Form	*makeForm(std::string, std::string) const;
	private:
		Form	*returnShrubbery(std::string target) const {return (new ShrubberyCreationForm(target));}
		Form	*returnPresidential(std::string target) const {return (new PresidentialPardonForm(target));}
		Form	*returnRobotomyRequest(std::string target) const {return (new RobotomyRequestForm(target));}
};

#endif
