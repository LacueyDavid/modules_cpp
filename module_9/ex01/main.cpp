#include "RPN.hpp"

void isOperatorInvalid(const std::string& token)
{
	const char* valid_operators[] = {"+", "-", "*", "/"};
	for (int i = 0; i < 4; ++i)
	{
		if (token == valid_operators[i])
			return;
	}
	throw std::runtime_error("Error op");
}

void isInputIncorrect(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;
	size_t count = 0;

	while (iss >> token)
	{
		if (isdigit(token[0]))
		{
			int number = std::atoi(token.c_str());
			if (number < 0 || number > 10)
				throw std::runtime_error("Error");
		}
		else
			isOperatorInvalid(token);
		if (count == 0)
			if (!isdigit(token[0]))
				throw std::runtime_error("Error");
		if (count == 1)
		{
			if (!isdigit(token[0]))
				throw std::runtime_error("Error");
		}
		if (count % 2 == 0 && count != 0)
		{
			isOperatorInvalid(token);
		}
		else if (!isdigit(token[0]))
			throw std::runtime_error("Error");
		count++;
	}
	if (count == 2)
		throw std::runtime_error("Error");
	isOperatorInvalid(token);
}

void isArgumentsIncorrect(int argc, const std::string &input)
{
	if (argc != 2)
		throw std::runtime_error("Error");
	isInputIncorrect(input);
}

int main(int argc, char **argv)
{
	try
	{
		isArgumentsIncorrect(argc, argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
		return EXIT_FAILURE;
	}
	RPN calculator(argv[1]);
}
