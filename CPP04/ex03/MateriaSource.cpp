#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void):_len(0) {
	for (int i = 0; i < 4; i++) {
		_memory[i] = 0;
	}
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource const &	MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs)
	{
		for (int i = 0; (i < 4); i++) {
			if (rhs._memory[i])
				_memory[i] = rhs._memory[i]->clone();
			else
				_memory[i] = 0;
		}
		_len = rhs._len;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; (i < 4 && _memory[i]); ++i) {
		delete _memory[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *src) {
	for (int i = 0; (i < 4); i++) {
		if (!_memory[i] && src) {
			_memory[i] = src;
			_len++;
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; (i < _len); i++)
	{
		if (!_memory[i]->getType().compare(type))
			return (_memory[i]->clone());
	}
	return (0);
}
