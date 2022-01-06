#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		AMateria	*_inventory[4];
		int			_len;
		std::string	_name;
	public:
		Character(void);
		Character(std::string);
		Character(Character const &);
		Character const &	operator=(Character const &);
		virtual ~Character(void);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};
#endif
