#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &);
		virtual ~Cat(void);
		Cat const &	operator=(Cat const &);
		virtual void	makeSound(void) const;
		Brain	*getBrain(void) const;
	private:
		Brain	*_brain;

};

#endif
