#include <iostream>

char *str_toupper(char *str)
{	
	for (size_t i = 0; str[i]; ++i)
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int ac, char **argv)
{	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";	
	else
	{
		for (int i = 1; i < ac; ++i)
			std::cout << str_toupper(argv[i]);
	}
	std::cout << '\n';
	return (0);
}
