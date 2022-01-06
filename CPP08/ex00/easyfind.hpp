#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>

class	NotFoundException : public std::exception {
public:
	virtual ~NotFoundException() throw() {}
	NotFoundException() throw() {}
	const char	*what() const throw() {
		return "Not found\n";
	}
private:
	std::string	_error;
};

template <typename T>
typename T::iterator	easyfind(T &container, int tofind) throw (NotFoundException)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), tofind);
	if (it != container.end())
		return (it);
	else
		throw NotFoundException();
}

#endif
