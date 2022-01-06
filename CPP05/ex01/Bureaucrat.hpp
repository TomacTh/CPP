#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		int	_grade;
	public:

		class	HIGHException : public std::exception{
			public:
				virtual const char*	what(void) const throw();
		};
		class	LOWException : public std::exception{
			public:
				virtual const char*	what(void) const throw();
		};

		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &) throw (std::exception);
		Bureaucrat(std::string, int) throw (std::exception);
		Bureaucrat const &	operator=(Bureaucrat const &);
		~Bureaucrat(void);

		std::string const	getName(void) const;
		int	getGrade(void) const;

		void	incrementGrade() throw(HIGHException);
		void	decrementGrade() throw(LOWException);

		void	signForm(Form &) const;
};

std::ostream &	operator<<(std::ostream & o,Bureaucrat const & rhs);

#endif
