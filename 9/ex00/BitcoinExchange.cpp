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
	return line;
}
// void BitcoinExchange::loadCSV(char* filename)
// {
// 	std::fstream infile(filename);
// 	// if (!infile)
// 	// {
// 	// 	throw std::exception();
// 	// }

// }

// std::tm extractDate(char *str)
// {}