#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> vec(1, 42);
	try
	{
		easyfind(vec, 3);
	}
	catch(NotFoundException const &e)
	{
		std::cout << e.what();
	}
	std::cout << "find: " << *easyfind(vec, 42) << "\n";

	std::list<int> list;
	for (int i = 0; i < 10; i++)
		list.push_front(i);
	try
	{
		easyfind(list, 10);
	}
	catch(NotFoundException const &e)
	{
		std::cout << e.what();
	}
	std::cout << "find: " << *easyfind(list, 7) << "\n";

}
