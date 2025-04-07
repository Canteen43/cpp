#pragma once
#include <map>
#include <ctime>
#include <fstream>
#include <iostream>
class BitcoinExchange
{
	private:
		std::map<struct tm, float> container;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void loadCSV(char* filename);
		std::string convertLine(std::string line);
};

// std::tm extractDate(char *str);