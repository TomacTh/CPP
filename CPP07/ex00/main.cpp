#include "whatever.hpp"

int main(void)
{
	char s1[]= "s1";
	char s2[] = "s2";

	const void *ptr = s1;
	const void *ptr2 = s2;
	std::cout << "ptr: " << ptr << '\n';
	std::cout << "ptr2: " << ptr2 << '\n';

	std::cout << "max float: " <<  max<float>(4.3f, 23.67f) << 'f' << std::endl;
	std::cout << "max long: " << max<long>(9223372036854775807, 1238823333) <<  std::endl;
	std::cout << "max void*: " << max<const void*>(ptr, ptr2) << std::endl;
	std::cout << "max string: " << max<char*>(s1, s2) << std::endl << std::endl;


	std::cout << "min float: " <<  min<float>(4.3f, 23.67f) << 'f' << std::endl;
	std::cout << "min long: " << min<long>(9223372036854775807, 1238823333) <<  std::endl;
	std::cout << "min void*: " << min<const void*>(ptr, ptr2) << std::endl;
	std::cout << "min string: " << min<char*>(s1, s2) << std::endl << std::endl;

	swap(ptr, ptr2);
	std::cout << "ptr: " << ptr << '\n';
	std::cout << "ptr2: " << ptr2 << '\n';
	std::cout << "swap s1 and s2: ";
	swap<char>(s1[1], s2[1]);
	std::cout << "\ns1: " << s1 << "\ns2: " << s2 << std::endl;
	int ft = 42;
	int ftplus = 43;
	std::cout << "swap 42 and 43\n";
	swap<int>(ft, ftplus);
	std::cout << "ft: " << ft << "\nftplus: " << ftplus << std::endl;


}
