#include "Ice.hpp"

Ice::Ice(void) {
	_type = "ice";
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(Ice const & src) {
	*this = src;
	std::cout << "Copy Ice constructor called" << std::endl;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called" << std::endl;
}

Ice const &	Ice::operator=(Ice const & rhs) {
	(void)rhs;
	return (*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria	*Ice::clone(void) const {
	return new Ice(*this);
}
