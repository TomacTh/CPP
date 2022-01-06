#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	std::cout << "\033[92mSubject Test\033[m\n\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	//THIS BLOCK SHOULD OUTPUT 12 LINES (4 = 2 constructors + 2 destructors for Animal) + (4 = 2 constructors + 2destructors for dog and cat) And (4 = 2 brain constructor + 2 brain destructor)
	//ESC[background_colour;Text_colourm output ESC[m”

	std::cout << "\n\033[92mCreate an array of 100 animal's pointer and fill half dog half cat \033[m\n\n";
	Animal	*animalsTab[20];
	for (int i = 0; i < 20; ++i) {
		std::cout << "\033[33m" << i << " \033[m";
		if (i % 2)
			animalsTab[i] = new Dog();
		else
			animalsTab[i] = new Cat();
	}
	std::cout << "\033[33mNow loop on tab and delete each element as animal\033[m\n";
	for (int i = 0; i < 20; ++i) {
		std::cout << "\033[33m" << i << " \033[m";
		delete animalsTab[i];
	}


	//PROVE THAT COPY ARE DEEP;
	std::cout << "\n\033[92mNow  we test that copy are deep so we are going to create a new cat make a copy of it and delete the original\n\n\033[m";
	const Cat	*cut = new Cat();
	Cat	copy(*cut);
	delete	cut;
	std::cout << "\033[33mYou can see that Brain and its ideas tab stills exist so it's a deep copy\033[m\n";
	Brain	*ptr = copy.getBrain();
	std::string	*tab = ptr->getIdeas();
	for (int i = 0; i < 100; ++i) {
		std::cout << "Ideas number " << i + 1 << ": " + tab[i] + "\n";
	}
	return (0);
}
