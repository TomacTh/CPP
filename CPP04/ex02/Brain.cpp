#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called\n";
}

Brain::Brain(Brain const & src)
{
	*this = src;
	std::cout << "Brain copy constructor called\n";
}

Brain const &	Brain::operator=(Brain const & rhs) {
	if (this != &rhs)
	{
		std::string *tab = rhs.getIdeas();
		for (int i = 0; i < 100; ++i) {
			ideas[i] = tab[i];
		}
	}
	return (*this);
}

std::string	*Brain::getIdeas(void) const {
	return (std::string*)ideas;
}
