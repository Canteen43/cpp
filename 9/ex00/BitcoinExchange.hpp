#pragma once
#include <map>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>  // for std::stringstream
#include <cstdio> // for sscanf()
#include <cstring> // for strlen()

// std::tm does not inherently support comparison operations so I have to provide it
struct tmFunctor
{
	bool operator()(const std::tm& lhs, const std::tm& rhs) const
	{
		if (lhs.tm_year != rhs.tm_year)
			return lhs.tm_year < rhs.tm_year;
		if (lhs.tm_mon != rhs.tm_mon)
			return lhs.tm_mon < rhs.tm_mon;
		return lhs.tm_mday < rhs.tm_mday;
	}
};

class BitcoinExchange
{
	private:
		std::map<std::tm, double, tmFunctor> container;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void loadCSV(char* filename);
		int addData(std::string line);
		std::string convertLine(std::string line);
};

bool isFormatted(char* format, char* string);
int extractDate(std::string datestr, std::tm& date);