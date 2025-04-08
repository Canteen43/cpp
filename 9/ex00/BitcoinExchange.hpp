#pragma once
#include <map>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>  // for std::stringstream
#include <cstdio> // for sscanf()
#include <cstring> // for strlen()
class BitcoinExchange
{
	private:
		std::map<std::tm, double> container;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void loadCSV(char* filename);
		std::string convertLine(std::string line);
};

bool isFormatted(char* format, char* string);
int extractDate(std::string datestr, std::tm& date);