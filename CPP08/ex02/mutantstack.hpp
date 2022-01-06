#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		MutantStack(MutantStack<T> const & src) {*this = src;}
		MutantStack<T> const &	operator=(MutantStack<T> const & rhs);
		typedef typename MutantStack<T>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		virtual ~MutantStack(){}
};

#endif
