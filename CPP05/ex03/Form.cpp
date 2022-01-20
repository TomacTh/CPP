#include "Form.hpp"

Form::Form(void) : _name("default"),_sign_grade(150),_exec_grade(150),_signed(false) {
	std::cout << "Default Form constructor called\n";
}

Form::~Form(void) {
	std::cout << "Form destructor called\n";
}

Form::Form(std::string name, int s_grade, int e_grade) throw (std::exception) :
	_name(name),
	_sign_grade(s_grade),
	_exec_grade(e_grade),
	_signed(false) {

	if (s_grade < 1)
		throw HIGHException("Signed Form: ");
	else if (s_grade > 150)
		throw LOWException("Signed Form: ");
	else if (e_grade < 1)
		throw HIGHException("Exec Form: ");
	else if (e_grade > 150)
		throw LOWException("Exec Form : ");
	std::cout << "Parametrical Form constructor called\n";
}

Form::Form(Form const & src) throw (std::exception) :
	_name(src.getName()),
	_sign_grade(src.getSignedGrade()),
	_exec_grade(src.getExecGrade()),
	_signed(false) {

	if (_sign_grade < 1)
		throw HIGHException("Signed Form: ");
	else if (_sign_grade > 150)
		throw LOWException("Signed Form: ");
	else if (_exec_grade < 1)
		throw HIGHException("Exec Form: ");
	else if (_exec_grade > 150)
		throw LOWException("Exec Form: ");
	std::cout << "Copy Form constructor called\n";
}

void	Form::beSigned(Bureaucrat const & bureaucrat) throw (Form::LOWException) {
	if (bureaucrat.getGrade() > _sign_grade)
		throw LOWException("Signed Form: Can't sign: ");
	else
		_signed = true;
}

void	Form::execute(Bureaucrat const & bureaucrat) const throw(std::exception) {
	if (!_signed)
		throw NOTSIGNEDException();
	else
	{
		if (bureaucrat.getGrade() <= _exec_grade)
			execute_function();
		else
			throw LOWException("Execution Form: ");
	}
}

std::string const	Form::getName(void) const {
	return (_name);
}

int	Form::getSignedGrade(void) const {
	return (_sign_grade);
}

int	Form::getExecGrade(void) const {
	return (_exec_grade);
}

bool Form::getSigned(void) const {
	return (_signed);
}

Form::HIGHException::HIGHException(std::string const str) throw() :_error(str + "* GRADE TOO HIGH! *\n") {}
Form::HIGHException::~HIGHException() throw() {}
const char *Form::HIGHException::what() const throw() { return (_error).c_str(); }

Form::LOWException::LOWException(std::string const str) throw() :_error(str + "* GRADE TOO LOW! *\n") {}
Form::LOWException::~LOWException() throw() {}
const char *Form::LOWException::what() const throw() { return (_error).c_str(); }

const char *Form::NOTSIGNEDException::what() const throw() { return ("* FORM IS NOT SIGNED *\n"); }

std::ostream &	operator<<(std::ostream & o,Form const & rhs) {

	std::string sign;
	if (rhs.getSigned())
		std::string sign = " is signed";
	else
		sign = " is not signed";
	o << rhs.getName() << sign << ", has a sign grade at: " << rhs.getSignedGrade() << " and a exectution grade at: " << rhs.getExecGrade() << std::endl;
	return (o);
}
