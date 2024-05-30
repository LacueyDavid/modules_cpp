#include <iostream>

void	megaphone(std::string str)
{
	for (std::string::size_type size = 0; size < str.size(); size++)
		str[size] = std::toupper(str[size]);
	std::cout << str;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 1;
	}
	for(int argument = 1; argument < argc; argument++)
		megaphone(argv[argument]);
	std::cout << "\n";
	return 0;
}
