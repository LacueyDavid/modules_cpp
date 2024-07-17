#include "scalarconvert.hpp"
#include <iostream>

void ScalarConvert::convert(const std::string& str)
{
	int value = static_cast<int>(std::atoi(str.c_str()));
	std::cout << value << "\n";
}
