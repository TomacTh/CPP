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
			virtual ~SpanException() throw();
			SpanException(const std::string& error) throw();
			const char	*what() const throw();
		private:
			std::string	_error;
	};

		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		virtual ~Span(void);
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
