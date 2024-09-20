#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>\n";
		return EXIT_FAILURE;
	}

	RPN rpn;
	try
	{
		long int result = rpn.evaluateRPN(argv[1]);
		std::cout << "Result: " << result << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
