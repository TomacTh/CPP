#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default construcor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	*this = src;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal const &	WrongAnimal::operator=(WrongAnimal const & rhs) {
	if (this != &rhs)
		type = rhs.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called\n";
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "* ... WrongAnimal sound ... *\n";
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}
