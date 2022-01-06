#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_memory[4];
		int			_len;
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &);
		MateriaSource const &	operator=(MateriaSource const &);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};
#endif
