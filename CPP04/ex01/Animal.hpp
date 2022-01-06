#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string);
		Animal(Animal const &);
		virtual ~Animal(void);
		Animal const &	operator=(Animal const &);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string	type;
};

#endif
