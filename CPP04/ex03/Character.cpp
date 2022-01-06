#include "Character.hpp"

Character::Character(void): _len(0) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = 0;
	}
	std::cout << "Default Character constructor called\n";
}

Character::Character(std::string str): _len(0), _name(str) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = 0;
	}
	std::cout << "Parametrical Character constructor called\n";
}

Character::Character(Character const & src) {
	*this = src;
	std::cout << "Copy Character constructor called\n";
}

Character const &	Character::operator=(Character const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
		_len = rhs._len;
		_name = rhs.getName();
	}
	return (*this);
}

Character::~Character(void) {
	for (int i = 0; i < _len; ++i)
		delete _inventory[i];
	std::cout << "Character destructor called\n";
}

std::string const &	Character::getName(void) const {
	return (_name);
}

void	Character::equip(AMateria *m) {
	if (_len < 4)
		_inventory[_len++] = m;
}

void	Character::unequip(int idx) {
	if (_len && idx < Character::_len && idx >= 0)
	{
		for (int i = idx ; i < _len - 1; i++) {
			_inventory[i] = _inventory[i + 1];
		}
		_inventory[--_len] = 0;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (_inventory[idx] != 0)
		_inventory[idx]->use(target);
}
