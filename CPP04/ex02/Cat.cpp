#include "Cat.hpp"

Cat::Cat(void) {
	type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default construcor called\n";
}

Cat::Cat(Cat const & src) {
	*this = src;
	std::cout << "Cat copy constructor called\n";
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat destructor called\n";
}

Cat const &	Cat::operator=(Cat const & rhs) {
	if (this != &rhs)
	{
		type = rhs.getType();
		_brain = new Brain(*rhs.getBrain());
	}
	return (*this);
}

Brain	*Cat::getBrain(void) const {
	return (_brain);
}

void	Cat::makeSound(void) const {
	std::cout << "* ... Miawwwwwweoo ... *\n";
}
