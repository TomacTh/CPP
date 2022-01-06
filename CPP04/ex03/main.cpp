#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	AMateria *tmpnull = src->createMateria("notknow");
	if (!tmpnull)
		std::cout << "\nNotknow type not found\n";
	std::cout << "unequip slot 1 and see that cannot use it after\n";
	me->unequip(1);
	me->use(1, *bob);

	std::cout << "Now copy src and me\n\n";
	std::cout  << "COPY SRC\n";
	IMateriaSource *src_copy = new MateriaSource((MateriaSource const &)*src);
	std::cout  << "\nCOPY ME\n";
	ICharacter	*me_copy = new Character((Character const &)*me);
	//src_clone->learnMateria(tmp);


	std::cout << std::endl;

	delete bob;
	delete tmp;
	delete src;
	delete me;
	std::cout << "\nsrc and me are deleted but we can still use their copies (deep copies)\n";
	me_copy->use(0, *me_copy);
	me_copy->equip(src_copy->createMateria("cure"));
	me_copy->use(1, *me_copy);
	delete src_copy;
	delete me_copy;
	return (0);
}

