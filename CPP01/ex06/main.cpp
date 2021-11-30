#include "Karen.hpp"

int main(int ac, char **argv)
{
	Karen karen;

	switch(ac)
	{
		case 2: karen.complain(argv[1]);
			break;
		default: std::cerr << "Bad number of arguments" << std::endl;	
	}
	return (0);
}
