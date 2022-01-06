#include "AMateria.hpp"

AMateria::AMateria(void) {
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) {
	*this = src;
	std::cout << "Copy AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type):_type(type) {
	std::cout << "Parametrical AMateria constructor called" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria const &	AMateria::operator=(AMateria const & rhs) {
	if (this != &rhs) {
		_type = rhs.getType();
	}
	return (*this);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Amateria no use " + target.getName() << std::endl;
}

std::string const &	AMateria::getType(void) const {
	return (_type);
}
