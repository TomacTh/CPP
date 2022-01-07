#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <errno.h>

void	print_int(const long long n)
{
	std::cout << "int: ";
	if (errno == ERANGE || n > INT_MAX || n < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(n) << "\n";
}

void	print_char(long long n)
{
	std::cout << "char: ";
	if (errno == ERANGE || n > CHAR_MAX || n < CHAR_MIN)
		std::cout << "impossible\n";
	else
	{
		char c = static_cast<char>(n);
		if (isprint(static_cast<int>(c)))
			std::cout << '\'' << c << '\'' << std::endl;
		else
			std::cout << "Non displayable\n";
	}
}

void	print_float(const float f)
{
	float f_p;
	
	if (!modff(f, &f_p))
		std::cout.precision(1);
	else
		std::cout.precision(std::numeric_limits< float >::max_digits10);
	std::cout << "float: " << f << "f\n";
}

void	print_double(const double d)
{
	double d_p;
	
	if (!modf(d, &d_p))
		std::cout.precision(1);
	else
		std::cout.precision(std::numeric_limits< double >::max_digits10);
	std::cout << "double: " << d << std::endl;
}

bool is_double(char const *str)
{
	char *endptr;
	double res = strtod(str, &endptr);
	std::cout << res << "\n";
	if (*endptr)
		return (false);
	else
	{
		print_char(static_cast<long long>(res));
		print_int(static_cast<long long>(res));
		print_float(static_cast<float>(res));
		print_double(res);
		return (true);
	}
}

bool is_float(char const *str) {
	char *endptr;
	float res = strtof(str, &endptr);

	if (!strcmp("f", endptr))
	{
		print_char(static_cast<long long>(res));
		print_int(static_cast<long long>(res));
		print_float(res);
		print_double(strtod(str, NULL)); //use instead of cast to have more capacity and precision
		return (true);
	}
	return (false);
}

bool is_char(char const *str) {
	if (strlen(str) == 3 && str[0] == '\'' && str[2] == '\'')
	{
		print_char(static_cast<long long>(str[1]));
		print_int(static_cast<long long>(str[1]));
		print_float(static_cast<float>(str[1]));
		print_double(static_cast<double>(str[1]));
		return (true);
	}
	return (false);
}

bool is_int(char const *str) {
	char *endptr;
	long long res = strtoll(str, &endptr, 10);
	if (*endptr)
		return (false);
	else
	{
		print_char(res);
		print_int(res);
		print_float(strtof(str, NULL)); //use instead of cast to have inf/-inff or  as overflow/underflow
		print_double(strtod(str, NULL)); //use instead of cast to have inff/-inff as overflow/underflow
		return (true);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::cout << std::fixed;
		if (is_int(av[1]))
			return (0);
		else if (is_double(av[1]))
			return (0);
		else if (is_float(av[1]))
			return (0);
		else if (is_char(av[1]))
			return (0);
		else
		{
			std::cerr << "Bad formatting, unknow type\n";
			return (1);
		}
	}
	else
		std::cerr << "Invalid usage [./progname] [literal value]\n";
	return (1);
}
