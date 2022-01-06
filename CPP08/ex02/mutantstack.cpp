#include "mutantstack.hpp"

template <typename T>
MutantStack<T> const &	MutantStack<T>::operator=(MutantStack<T> const & rhs)
{
	if (this != &rhs)
		this->c = rhs.c;
	return (*this);
}
