#include "serialization.hpp"
#include <iostream>

int main()
{
	Data *data = new Data();
	Data *data2;

	data->x = 42;
	data->y = 43;

	uintptr_t ptr;
	ptr = Serializer::serialize(data);
	data2 = Serializer::deserialize(ptr);

	if (data2 == data)
		std::cout << "it's the same address.\n";
	delete data;
}
