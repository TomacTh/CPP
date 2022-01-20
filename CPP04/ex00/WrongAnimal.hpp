#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP
# include "iostream"

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string);
		WrongAnimal(WrongAnimal const &);
		virtual ~WrongAnimal(void);
		WrongAnimal const &	operator=(WrongAnimal const &);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string	type;
};
#endif
