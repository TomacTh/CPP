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
				HIGHException(std::string const str) throw();
				virtual ~HIGHException() throw();
				virtual const char*	what() const throw();
		};
		class	LOWException : public std::exception{
			private:
				std::string	const _error;
			public:
				virtual ~LOWException() throw();
				LOWException(std::string const str) throw();
				virtual const char*	what() const throw();
		};
		class	NOTSIGNEDException : public std::exception{
			public:
				virtual const char*	what(void) const throw();
		};

		Form(std::string, int, int) throw (std::exception);
		virtual ~Form(void);

		void			beSigned(Bureaucrat const &) throw(Form::LOWException);
		void			execute(Bureaucrat const & executor) const throw(std::exception);

		std::string const	getName(void) const;
		int	getSignedGrade(void) const;
		int	getExecGrade(void) const;
		bool getSigned(void) const;

	protected:
		virtual	void	execute_function(void) const = 0;

	private:
		std::string const	_name;
		int	const			_sign_grade;
		int const			_exec_grade;
		bool				_signed;
		Form(void);
		Form(Form const &) throw (std::exception);
		Form const &	operator=(Form const &);
};

std::ostream &	operator<<(std::ostream & o,Form const & rhs);

#endif


