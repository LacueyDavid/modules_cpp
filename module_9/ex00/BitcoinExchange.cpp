#include "BitcoinExchange.hpp"
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::cout << "calling constructor\n";
	csv_file.open("data.csv");
	input.open(filename.c_str());
	if (!csv_file.is_open())
		throw std::runtime_error("Error: could not open file: data.csv\n");
	if (!input.is_open())
	{
		std::ostringstream oss;
		oss << "Error: could not open file: " << filename;
		throw std::runtime_error(oss.str());
	}
	fill_map_with_date_and_values();
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "calling destructor\n";
	if (csv_file.is_open())
		csv_file.close();
	if (input.is_open())
		input.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other __attribute__((unused)))
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other __attribute__((unused)))
{
	return *this;
}

void	BitcoinExchange::verify_csv_is_correct(const std::string line)
{
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid header in file data.csv\n");
}

void	BitcoinExchange::fill_map_with_date_and_values()
{
	std::string line;

	std::getline(csv_file, line);
	verify_csv_is_correct(line);
	while (getline(csv_file, line))
	{
		std::
	}
}

void BitcoinExchange::load()
{
	return ;
}

void BitcoinExchange::display()
{
	return ;
}
