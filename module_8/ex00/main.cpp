#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;

	vec.push_back(40);
	vec.push_back(41);
	vec.push_back(42);
	vec.push_back(43);

	std::vector<int>::iterator it;
	it = easyfind(vec, 42);

	if (it != vec.end())
		std::cout << "i find: " << *it << "\n";
	else
		std::cout << "don't find it\n";

	it = easyfind(vec, 2);

	if (it != vec.end())
		std::cout << "i find: " << *it << "\n";
	else
		std::cout << "don't find it\n";
}
