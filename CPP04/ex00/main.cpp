#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	//Now with wrongAnimal
	const WrongAnimal *w = new WrongCat();
	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	delete meta;
	delete j;
	delete i;
	delete w;
	return (0);
}

