#include "BitcoinExchange.hpp"

// private to not use /////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(BitcoinExchange &other __attribute__((unused)))
{
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other __attribute__((unused)))
{
	return *this;
}

// public /////////////////////////////////////////////////////////////////////

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
	try
	{
		fill_map_with_date_and_values();
	}
	catch (const std::exception& e)
	{
		throw ;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "calling destructor\n";
	if (csv_file.is_open())
		csv_file.close();
	if (input.is_open())
		input.close();
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
		time_t date = extract_date_from_current_line_in_csv(line);
		double value = extract_value_from_current_line_in_csv(line);
		if (valuesAt.find(date) != valuesAt.end())
			throw std::runtime_error("Error: duplicate date in file: data_csv");
		valuesAt[date] = value;
	}
}

time_t	BitcoinExchange::extract_date_from_current_line_in_csv(const std::string line)
{
	std::string date;
	date = line.substr(0, line.find(','));
	date = date.substr(0, date.find_last_not_of(' ') + 1);
	date = date.substr(date.find_first_not_of(' '));
	struct tm dateTime = {};
	char formattedDate[11];
	if (strptime(date.c_str(), "%Y-%m-%d", &dateTime) == NULL)
		throw std::runtime_error("Error: invalid date format in file: data.csv");
	strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", &dateTime);
	if (date != formattedDate)
		throw std::runtime_error("Error: invalid date in file: data.csv");
	int year = dateTime.tm_year + 1900;
	int month = dateTime.tm_mon + 1;
	int day = dateTime.tm_mday;
	bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	int daysInMonth[] = {31, isLeapYear ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > daysInMonth[month - 1])
		throw std::runtime_error("Error: invalid day in file: data.csv");
	time_t timestamp = mktime(&dateTime);
	if (timestamp == -1)
		throw std::runtime_error("Error: could not convert date in file: data.csv");
	return timestamp;
}

double	BitcoinExchange::extract_value_from_current_line_in_csv(const std::string line)
{
	std::string value;
	value = line.substr(line.find(',') + 1);
	value = value.substr(value.find_first_not_of(' '));
	value = value.substr(0, value.find_last_not_of(' ') + 1);
	return toDouble(value);
}

time_t	BitcoinExchange::extract_date_from_current_line_in_input(const std::string line)
{
	std::string date;
	date = line.substr(0, line.find('|'));
	date = date.substr(0, date.find_last_not_of(' ') + 1);
	date = date.substr(date.find_first_not_of(' '));
	struct tm dateTime = {};
	char formattedDate[11];
	if (strptime(date.c_str(), "%Y-%m-%d", &dateTime) == NULL)
		throw std::runtime_error("Error: invalid date format in file: data.csv");
	strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", &dateTime);
	if (date != formattedDate)
		throw std::runtime_error("Error: invalid date in file: data.csv");
	int year = dateTime.tm_year + 1900;
	int month = dateTime.tm_mon + 1;
	int day = dateTime.tm_mday;
	bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	int daysInMonth[] = {31, isLeapYear ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > daysInMonth[month - 1])
		throw std::runtime_error("Error: invalid day in file: data.csv");
	time_t timestamp = mktime(&dateTime);
	if (timestamp == -1)
		throw std::runtime_error("Error: could not convert date in file: data.csv");
	return timestamp;
}

double	BitcoinExchange::extract_value_from_current_line_in_input(const std::string line)
{
	std::string value;
	value = line.substr(line.find('|') + 1);
	value = value.substr(value.find_first_not_of(' '));
	value = value.substr(0, value.find_last_not_of(' ') + 1);
	return toDouble(value);
}

double	BitcoinExchange::toDouble(const std::string value)
{
	char* end;
	errno = 0;

	double result = std::strtod(value.c_str(), &end);
	if (errno == ERANGE || *end != '\0')
		throw std::invalid_argument("Error: invalid input string");
	if (result < 0)
		throw std::out_of_range("Error: value is less than 0");
	if (result > static_cast<double>(INT_MAX))
		throw std::out_of_range("Error: value exceeds INT_MAX");

	return result;
}

std::string BitcoinExchange::dateToString(time_t date)
{
    struct tm *timeinfo = localtime(&date);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return std::string(buffer);
}

void BitcoinExchange::printValue(std::map<time_t, double>::iterator it, double value)
{
	// if (value < 0)
	// 	std::cerr << "Error: not a positive number.\n";
	// else if (value > 1000)
	// 	std::cerr << "Error: number out of scope.\n";
	// else
	// 	std::cout << it->second * value << "\n";
	std::cout << it->second << "\n";
	(void)value;
}

bool BitcoinExchange::valueNotFoundAt(time_t date)
{
	return valuesAt.find(date) == valuesAt.end();
}

void BitcoinExchange::printInfos(time_t date, double value)
{
	std::cout << dateToString(date) << " => " << value << " = ";
	std::map<time_t, double>::iterator it = valuesAt.find(date);
	if (valueNotFoundAt(date))
	{
		valuesAt[date] = 0; // add value to decreament and found the good one
		std::map<time_t, double>::iterator it = valuesAt.find(date);
		if (it != valuesAt.begin())
		{
			it--; // decreament here to find the good one
			printValue(it, value); // print the good one
		}
		else
			std::cout << "0\n";
		valuesAt.erase(date);
	}
	else
		printValue(it, value);
	return ;
}

void BitcoinExchange::display()
{
	std::string line;

	std::getline(input, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid header in input file");
	while (std::getline(input, line))
	{
		time_t date = extract_date_from_current_line_in_input(line);
		double value = extract_value_from_current_line_in_input(line);
		printInfos(date, value);
	}
	return ;
}
