#include <iostream>
#include <math.h>
#include "Base.hpp"

Base::Base(){}
Base::Base(Base const &){};
Base &	Base::operator=(Base const &){return *this;}
Base::~Base(){};


Base * generate(void)
{
	srand(time(0));
	int res = rand() % 3;
	if (res == 2)
		return new A;
	else if (res == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch (std::exception) {
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B\n";
		}
		catch (std::exception) {
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C\n";
			} catch (std::exception) {}
		}
	}
}

int main(void) {
	Base *test = generate();
	identify(test);
	identify(*test);
}
