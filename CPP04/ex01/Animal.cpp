#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default construcor called\n";
}

Animal::Animal(Animal const & src) {
	*this = src;
	std::cout << "Animal copy constructor called\n";
}

Animal const &	Animal::operator=(Animal const & rhs) {
	if (this != &rhs)
		type = rhs.getType();
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called\n";
}

void	Animal::makeSound(void) const {
	std::cout << "* ... Animal sound ... *\n";
}

std::string	Animal::getType(void) const {
	return (type);
}
