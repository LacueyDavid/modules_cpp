// You have to create a program which outputs the value of a certain amount of bitcoin
// on a certain date.

// This program must use a database in csv format which will represent bitcoin price
// over time. This database is provided with this subject.

// The program will take as input a second database, storing the different prices/dates
// to evaluate.

// date | value

//format == year-month-day

// float or integer between 0 and 1000

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <filename>\n";
		return EXIT_FAILURE;
	}
	try
	{
		BitcoinExchange exchange(argv[1]);
		exchange.display();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
