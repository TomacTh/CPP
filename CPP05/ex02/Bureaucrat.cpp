#include "Bureaucrat.hpp"

//CONSTRUCTORS, DESTUCTOR AND OVERLOAD

Bureaucrat::Bureaucrat(void):_name("default"), _grade(150) {
	std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string str, int grade) throw (std::exception):_name(str), _grade(grade) {
	if (_grade < 1)
		throw HIGHException();
	else if (_grade > 150)
		throw LOWException();
	std::cout << "Parametrical Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) throw (std::exception):_name(src.getName()), _grade(src.getGrade()) {
	if (_grade < 1)
		throw HIGHException();
	else if (_grade > 150)
		throw LOWException();
	std::cout << "Copy Bureaucrat constructor called\n";
}

Bureaucrat const &	Bureaucrat::operator=(Bureaucrat const & rhs)  {
	if (this != &rhs)
		*this = Bureaucrat(rhs);
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "BureauCrat destructor called\n";
}
//PUBLIC FUNCTION MEMBER
void	Bureaucrat::decrementGrade(void) throw (LOWException){
	if (_grade + 1 > 150)
		throw LOWException();
	_grade++;
}

void	Bureaucrat::incrementGrade(void) throw(HIGHException) {
	if (_grade - 1 < 1)
		throw HIGHException();
	_grade--;
}

void	Bureaucrat::signForm(Form & form) const{
	if (form.getSigned())
		std::cout << "Bureaucrat " << _name << " can't sign form " << _name << " beceause it is already signed!\n";
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << "Bureaucrat " << _name << " signs form " << form.getName() << std::endl;
		}
		catch (Form::LOWException)
		{
			std::cout << "Bureaucrat " << _name << " can't sign form " << _name << " beceause grade " << _grade << " is to low\n";
		}
	}
}

void	Bureaucrat::executeForm(Form const & form) const {
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;

	}
	catch (std::exception const &e)
	{
		std::cerr << _name << " cannot execute form " << form.getName() << " beceause:\n" << e.what();
	}
}
//EXCEPTION NESTED CLASS

const char	*Bureaucrat::HIGHException::what(void) const throw() { return ("* GRADE TOO HIGH! *\n"); }
const char	*Bureaucrat::LOWException::what(void) const throw() { return ("* GRADE TOO LOW! *\n"); }

//ACCESSORS

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

std::string const	Bureaucrat::getName(void) const {
	return (_name);
}

std::ostream &	operator<<(std::ostream & o,Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}
