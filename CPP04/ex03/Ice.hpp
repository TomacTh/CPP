#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class	Ice : public AMateria {
	public:
		Ice(void);
		Ice(Ice const &);
		Ice const &	operator=(Ice const &);
		virtual ~Ice(void);

		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;

};
#endif
