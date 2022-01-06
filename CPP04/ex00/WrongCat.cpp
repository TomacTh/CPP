#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	type = "WrongCat";
	std::cout << "WrongCat default construcor called\n";
}

WrongCat::WrongCat(WrongCat const & src) {
	*this = src;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called\n";
}

WrongCat const &	WrongCat::operator=(WrongCat const & rhs) {
	if (this != &rhs)
		type = rhs.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "* ... WRONGMiawwwwwweoo ... *\n";
}
