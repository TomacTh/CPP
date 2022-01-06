#include "span.hpp"
#include <list>

void	print(int i)
{
	std::cout << i << "\n";
}

int main (void)
{
	//subject_tests
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; //2
		std::cout << sp.longestSpan() << std::endl; //14
	}
	std::cout << std::endl;

	Span *ispan = new Span();
	try
	{
		ispan->longestSpan();
	}
	catch (std::exception const &e)
	{
		std::cout << e.what();
	}

	try
	{
		ispan->addNumber(400);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what();
	}
	delete ispan;
	//can contain 8 elements
	ispan = new Span(8);
	//now 7;
	ispan->addNumber(400);
	// try to add a range of 8 int's iterators;
	int arr[] = {1, 2, 3, 4, 5, 10, 25, 100};
	std::vector<int> vectint(arr, arr + sizeof(arr) / sizeof(int));
	try
	{
		ispan->addNumber(vectint.begin(), vectint.end());
	}
	catch (std::exception const &e)
	{
		std::cout << e.what();
	}
	//try to add a range of 7
	try
	{
		ispan->addNumber(vectint.begin() + 1, vectint.end());
		std::cout << "successfully add iterators range!!\n";
		std::cout << "LONGESTSPAN: " << ispan->longestSpan() << std::endl;
		std::cout << "SHORTESTPAN: " << ispan->shortestSpan() << std::endl;

	}
	catch (std::exception const &e)
	{
		std::cout << e.what();
	}
	delete ispan;


	std::cout << std::endl;
	std::list<int> i_list;
	for (int i = 42; i < 4242; i++)
		i_list.push_back(i);
	Span spanlist(static_cast<unsigned int>(i_list.size()));
	spanlist.addNumber(i_list.begin(), i_list.end());
	std::vector<int> tab = spanlist.getTab();
	std::for_each(tab.begin(), tab.end(), print);
}
