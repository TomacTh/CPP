#include <iostream>

struct Data {int data;};

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
	mydata.data = 42;
	uintptr_t res_serialize = serialize(&mydata);
	Data *res_deserialize = deserialize(res_serialize);
	if (res_deserialize == &mydata)
		std::cout << "Exercice is good: " << res_deserialize << " : " << &mydata << std::endl;
	std::cout << res_deserialize->data << "\n";
	return (0);
}
