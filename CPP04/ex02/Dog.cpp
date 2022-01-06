#include "Dog.hpp"

Dog::Dog(void) {
	type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default construcor called\n";
}

Dog::Dog(Dog const & src) {
	*this = src;
	std::cout << "Dog copy constructor called\n";
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog destructor called\n";
}

Dog const &	Dog::operator=(Dog const & rhs) {
	if (this != &rhs)
	{
		type = rhs.getType();
		_brain = new Brain(*rhs.getBrain());
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "* ... Waouf Waouf ... *\n";
}

Brain	*Dog::getBrain(void) const {
	return (_brain);
}
