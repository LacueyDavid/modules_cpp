#include "array.hpp"
#include <iostream>

int main()
{
	Array<int> array(10);
	for (std::size_t i = 0; i < 10; ++i)
	{
		array[i] = i;
		std::cout << array[i] << "\n";
	}

	Array<std::string> arraya(10);
	for (std::size_t i = 0; i < 10; ++i)
	{
		arraya[i] = "salut";
		std::cout << arraya[i] << "\n";
	}
	try
	{
		array[100] = 12;
	}
	catch (const std::exception& e)
	{
		std::cout << "i catch: " << e.what() << "\n";
	}
}
