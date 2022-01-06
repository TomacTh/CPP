#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	public:
		Brain(void);
		virtual ~Brain(void);
		Brain(Brain const &);
		Brain const &	operator=(Brain const &);
		std::string		*getIdeas(void) const;
private:
		std::string	ideas[100];
};

#endif
