#include "span.hpp"

unsigned int	Span::longestSpan(void) const throw (SpanException)
{
	if (_vect.size() <= 1)
		throw SpanException("Vector must have 2 elements minimum to find shortestSpan\n");
	else
		return (*std::max_element(_vect.begin(), _vect.end()) - *std::min_element(_vect.begin(), _vect.end()));
}

unsigned int	Span::shortestSpan(void) const throw (SpanException)
{
	if (_vect.size() <= 1)
		throw SpanException("Vector must have 2 elements minimum to find longestSpan\n");
	else
	{
		std::vector<int>	copy(_vect);
		std::sort(copy.begin(), copy.end());
		std::vector<int>::iterator	begin = copy.begin();
		std::vector<int>::iterator	end = copy.end();

		unsigned int min =  *(begin + 1) - *begin;
		while (++begin < end - 1)
		{
			if (static_cast<unsigned int>(*(begin + 1) - *begin) < min)
				min = (*(begin + 1) - *begin);
		}
		return (min);
	}
}
Span::Span(void) : _len(0) {}

Span::Span(unsigned int N) : _len(N) {}

Span::Span(Span const & src) { *this = src; }

Span::~Span(void) {}

Span const &	Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		if (_len != rhs._len)
		{
			_len = rhs._len;
			_vect.resize(rhs._vect.size());
		}
		std::copy(rhs._vect.begin(), rhs._vect.end(), _vect.begin());
	}
	return (*this);
}

void	Span::addNumber(int const &n) throw (Span::SpanException)
{
	if (_vect.size() >= _len)
		throw SpanException("cannot add a number, vector is already full\n");
	else
		_vect.push_back(n);
}


Span::SpanException::~SpanException(void) throw() {}
Span::SpanException::SpanException(const std::string& error) throw() : _error("* SPAN EXCEPTION *: " + error) {}
const char	*Span::SpanException::what(void) const throw() { return _error.c_str(); }
