#include "scalarconvert.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

bool isOk(const std::string& str)
{
	for (std::size_t i = 0; i < str.size() - 1; ++i)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

void ScalarConvert::convert(const std::string& str)
{
	if (str == "nanf")
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "char: impossible \n";
		std::cout << "int: impossible \n";
		std::cout << "floar: " << f << "\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
	}
	else if (str == "-inff")
	{
		float f = -std::numeric_limits<float>::infinity();
		std::cout << "char: impossible \n";
		std::cout << "int: impossible \n";
		std::cout << "floar: " << f << "\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
	}
	else if (str == "+inff")
	{
		float f = std::numeric_limits<float>::infinity();
		std::cout << "char: impossible \n";
		std::cout << "int: impossible \n";
		std::cout << "floar: " << f << "\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
	}
	else if (str == "+inf")
	{
		double d = std::numeric_limits<double>::infinity();
		std::cout << "char: impossible \n";
		std::cout << "int: impossible \n";
		std::cout << "float: " << static_cast<float>(d) << "\n";
		std::cout << "double: " << d << "\n";

	}
	else if (str == "-inf")
	{
		double d = -std::numeric_limits<double>::infinity();
		std::cout << "char: impossible \n";
		std::cout << "int: impossible \n";
		std::cout << "float: " << static_cast<float>(d) << "\n";
		std::cout << "double: " << d << "\n";
	}
	else if (str == "nan")
	{
		double d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "char: impossible \n";
		std::cout << "int: impossible \n";
		std::cout << "float: " << static_cast<float>(d) << "\n";
		std::cout << "double: " << d << "\n";
	}
	else if (str.size() == 1 && std::isprint(str[0]))
	{
		char c = str[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		std::cout << "char: " << c << "\n";
		std::cout << "int: " << i << "\n";
		std::cout << "floar: " << f << "\n";
		std::cout << "double: " << d << "\n";
	}
	else if (str.find(".") == std::string::npos && str.find("f") == std::string::npos)
	{
		int i = std::atoi(str.c_str());
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		if (isprint(i))
			std::cout << "char: " << static_cast<char>(i) << "\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << i << "\n";
		std::cout << "floar: " << f << "\n";
		std::cout << "double: " << d << "\n";
	}
	else if (str[str.size() - 1] == 'f' && isOk(str))
	{
		std::cout << "not ok\n";
		float f = std::atof(str.c_str());
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);
		if (isprint(f))
			std::cout << "char: " << static_cast<char>(f) << "\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << i << "\n";
		std::cout << "floar: " << f << "\n";
		std::cout << "double: " << d << "\n";
	}
	else if (isOk(str))
	{
		double d = std::strtod(str.c_str(), 0);
		float f = static_cast<float>(d);
		int i = static_cast<int>(d);
		if (isprint(f))
			std::cout << "char: " << static_cast<char>(d) << "\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << i << "\n";
		std::cout << "floar: " << f << "\n";
		std::cout << "double: " << d << "\n";
	}
}
