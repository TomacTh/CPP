#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	public:

		class	SpanException : public std::exception {
		public:
			virtual ~SpanException() throw() {}
			SpanException(const std::string& error) throw() : _error("* SPAN EXCEPTION *: " + error) {}
			const char	*what() const throw() {
				return _error.c_str();
			}
		private:
			std::string	_error;
	};

		Span(void) : _len(0) {}
		Span(unsigned int N) : _len(N) {}
		Span(Span const & src) {*this = src;}
		virtual ~Span(void) {}
		Span const &	operator=(Span const &);

		void	addNumber(int const &) throw (Span::SpanException);

		template <typename T>
		void	addNumber(T begin, T end) throw (Span::SpanException)
		{
			if (static_cast<size_t>(std::distance(begin, end)) > static_cast<size_t>((_len) - _vect.size()))
				throw SpanException("Range is too large for vector\n");
			else
				std::copy(begin, end, std::back_inserter(_vect));
		}

		unsigned int		shortestSpan(void) const throw (SpanException);
		unsigned int		longestSpan(void) const throw (SpanException);
		std::vector<int> const	&getTab(void) const {return _vect;}
	private:
		unsigned int 	_len;
		std::vector<int> _vect;
};

#endif
