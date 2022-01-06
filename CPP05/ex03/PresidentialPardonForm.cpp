#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form::Form("PresidentialPardonForm", 25, 5),_target(target) {
	std::cout << "Default PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form::Form("PresidentialPardonForm", 25, 5), _target(src._target) {
	std::cout << "Copy PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm const &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs)
		*this = PresidentialPardonForm(rhs);
	return (*this);
}

void	PresidentialPardonForm::execute_function(void) const {
	std::cout << "Zafod Beeblebrox pardons " << _target << " beceause he is in a nice day" << std::endl;
}
