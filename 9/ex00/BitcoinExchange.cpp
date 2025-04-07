#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	container = other.container;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	container = other.container;
	return *this;
}
BitcoinExchange::~BitcoinExchange()
{}
std::string BitcoinExchange::convertLine(std::string line)
{
	// Splitting input line and checking format
	if (line.size() <= 13)
		return "Error: invalid format";
	std::string datestring = line.substr(0, 10);
	std::string middlestr = line.substr(10, 3);
	if (middlestr != " | ")
		return "Error: invalid format";
	std::string valuestr = line.substr(13);

	// Converting std::string datestring to std::tm date
	std::tm date;
	if (extractDate(datestring, date) == -1)
	{
		std::ostringstream errorMessage;
		errorMessage << "Error: bad input => " << datestring;
		return errorMessage.str();
	}
	std::cout << std::asctime(&date);

	// Preparing line to return
	std::ostringstream oss;
	oss << datestring << middlestr << valuestr;
	return oss.str();
}
// void BitcoinExchange::loadCSV(char* filename)
// {
// 	std::fstream infile(filename);
// 	// if (!infile)
// 	// {
// 	// 	throw std::exception();
// 	// }

// }

int extractDate(std::string datestr, std::tm& date)
{
	Setting the date to zero
	date = {0};

	date.tm_year = atoi(datestr.substr(0, 4));
	if (date.tm_year == 0)
		return -1;
	date.tm_year -= 1900;
	// int i = 0;
	// while (i < 4)
	// {
	// 	if (datestr[i] < '0' || datestr[i] > '9')
	// 		return -1;
	// 	date.tm_year = date.tm_year * 10 + datestr - 1;
	// 	i++;
	// }
	// // for (int i = 0; datestr[i]; ++i)
	// // {
	// // 	if (i == 4 || i == 7 && datestr[i] != '-')
	// // 		return -1;
	// // }
	date.tm_year = year - 1900;
	date.tm_mon = month -1;
	date.tm_mday = day;
	return 0;
}

// Parsing is really hard. Standard functions are not strict enough.