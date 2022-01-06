#include "Cat.hpp"

Cat::Cat(void) {
	type = "Cat";
	std::cout << "Cat default construcor called\n";
}

Cat::Cat(Cat const & src) {
	*this = src;
	std::cout << "Cat copy constructor called\n";
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called\n";
}

Cat const &	Cat::operator=(Cat const & rhs) {
	if (this != &rhs)
		type = rhs.getType();
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "* ... Miawwwwwweoo ... *\n";
}
