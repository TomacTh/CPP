#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

#include <fstream>

class PresidentialPardonForm : public Form {
	private:
		std::string	_target;
		virtual	void	execute_function(void) const;
	public:
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm const &	operator=(PresidentialPardonForm const &);
		virtual ~PresidentialPardonForm(){}

};

#endif
