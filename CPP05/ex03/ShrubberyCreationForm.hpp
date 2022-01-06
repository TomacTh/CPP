#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {
	private:
		std::string	_target;
		virtual	void	execute_function(void) const;
	public:
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		ShrubberyCreationForm const &	operator=(ShrubberyCreationForm const &);
		virtual ~ShrubberyCreationForm(){}
};

#endif
