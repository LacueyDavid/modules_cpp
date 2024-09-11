#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
private:
	std::ifstream input;
	std::ifstream csv_file;
	std::map<time_t, float> valuesAt;

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void	fill_map_with_date_and_values();
	void	verify_csv_is_correct(const std::string line);
public:
	BitcoinExchange(std::string filename);
	~BitcoinExchange();
	void load();
	void display();
};

#endif
