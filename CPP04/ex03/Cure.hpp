#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class	Cure : public AMateria {
	public:
		Cure(void);
		Cure(Cure const &);
		Cure const &	operator=(Cure const &);
		virtual ~Cure(void);

		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;

};
#endif

