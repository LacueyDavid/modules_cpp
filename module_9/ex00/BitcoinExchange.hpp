#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <climits>
#include <cerrno>

class BitcoinExchange
{
private:
	std::ifstream input;
	std::ifstream csv_file;
	std::map<time_t, double> valuesAt;

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void	fill_map_with_date_and_values();
	void	verify_csv_is_correct(const std::string line);
	time_t	extract_date_from_current_line_in_csv(const std::string line);
	double	extract_value_from_current_line_in_csv(const std::string line);
	time_t	extract_date_from_current_line_in_input(const std::string line);
	double	extract_value_from_current_line_in_input(const std::string line);
	double	toDouble(const std::string value);
	double	toDoubleInput(const std::string& value);
	void	printValue(std::map<time_t, double>::iterator it, double value);
	bool	valueNotFoundAt(time_t date);
	void	printInfos(time_t date, std::string dateStr, double value);
	std::string	dateToString(time_t date);
	std::string extractDateStr(const std::string line);

public:
	BitcoinExchange(std::string filename);
	~BitcoinExchange();
	void display();
};

#endif
