#include "Array.hpp"

int main(void)
{
	Array  <int>int_arr(4);
	Array <float>empty_arr(0);

	try
	{
		empty_arr[0];
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << ": try to access an element out of array\n\n";
	}

	std::cout << "verif that array's elements are initialized with the good values\n";
	int *ptrint = new int();
	if (*ptrint == int_arr[0])
		std::cout << "[ " << *ptrint << " ]:" << " good value ;)\n\n";
	delete ptrint;

	for (unsigned int i = 0; i < int_arr.size(); i++)
	{
		int_arr[i] = 42 - i;
		std::cout << i << ": " << int_arr[i] << std::endl;
	}

	Array <int>copy_arr = int_arr;
	std::cout << "\nCopy int_arr into copy_arr and change first value after (should be unchanged in copy_arr)\n";
	int_arr[0] = -1;
	std::cout << "int_arr 0: " << int_arr[0] << std::endl;
	for (unsigned int i = 0; i < copy_arr.size(); i++)
	{
		std::cout << i << ": " << copy_arr[i] << std::endl;
	}
}
