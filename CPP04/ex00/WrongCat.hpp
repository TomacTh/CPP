#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &);
		virtual ~WrongCat(void);
		WrongCat const &	operator=(WrongCat const &);
		virtual void	makeSound(void) const;
};

#endif
