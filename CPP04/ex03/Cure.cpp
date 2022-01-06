#include "Cure.hpp"

Cure::Cure(void) {
	_type = "cure";
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(Cure const & src) {
	*this = src;
	std::cout << "Copy Cure constructor called" << std::endl;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called" << std::endl;
}

Cure const &	Cure::operator=(Cure const & rhs) {
	(void)rhs;
	return (*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n" ;
}

AMateria	*Cure::clone(void) const {
	return new Cure(*this);
}
