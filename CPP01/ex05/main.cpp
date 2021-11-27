#include "Karen.hpp"

int main(void)
{
	Karen karen;

	karen.complain("BAD");
	karen.complain("INFO");
	std::cout << std::endl;
	karen.complain("DEBUG");
	std::cout << std::endl;
	karen.complain("WARNING");
	std::cout << std::endl;
	karen.complain("ERROR");
	return (0);
}
