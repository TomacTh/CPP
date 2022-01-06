#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		class	HIGHException : public std::exception{
			private:
				std::string	 const _error;
			public:
				HIGHException(std::string const str) throw() :_error(str + "* GRADE TOO HIGH! *\n") {}
				virtual ~HIGHException() throw() {}
				virtual const char*	what() const throw() {
					return (_error).c_str();
				}
		};

		class	LOWException : public std::exception{
			private:
				std::string	const _error;
			public:
				virtual ~LOWException() throw() {}
				LOWException(std::string const str) :_error(str + "* GRADE TOO LOW! *\n") {}
				virtual const char*	what() const throw() {
					return (_error).c_str();
				}
		};

		Form(std::string, int, int) throw (std::exception);
		Form(void);
		Form(Form const &) throw (std::exception);
		Form const &	operator=(Form const &);
		~Form(void);

		void	beSigned(Bureaucrat const &) throw(Form::LOWException);

		std::string const	getName(void) const;
		int	getSignedGrade(void) const;
		int	getExecGrade(void) const;
		bool getSigned(void) const;

	private:
		std::string const	_name;
		int	const			_sign_grade;
		int const			_exec_grade;
		bool				_signed;
};

std::ostream &	operator<<(std::ostream & o,Form const & rhs);

#endif


