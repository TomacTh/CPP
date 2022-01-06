#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const &);
		virtual ~AMateria(void);
		AMateria const &	operator=(AMateria const &);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif
