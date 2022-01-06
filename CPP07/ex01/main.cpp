#include "iter.hpp"
#include "string.h"


int main(void)
{
	char str[] = "abcdefghijkLmnOpqrst";
	size_t len = 20;
	int tabint[] = {1, 2, 3, 4, 5, 6};

	iter<char>(str, len, toupper_custom<char>);
	iter<char>(str, len, print);
	std::cout << std::endl;

	iter<char>(str, len, inc<char>);
	iter<char>(str, len, print);
	std::cout << std::endl;

	iter<int>(tabint, static_cast<size_t>(6), inc);
	iter<int>(tabint, static_cast<size_t>(6), print);
}
