#include <iostream>

struct Data {};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main (void)
{
	Data mydata;
	uintptr_t res_serialize = serialize(&mydata);
	Data *res_deserialize = deserialize(res_serialize);
	if (res_deserialize == &mydata)
		std::cout << "Exercice is good: " << res_deserialize << " : " << &mydata << std::endl;
	return (0);
}
