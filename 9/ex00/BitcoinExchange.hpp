#pragma once
#include <map>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>  // for std::stringstream
#include <cstdio> // for scanf()
#include <cstdlib> // for atoi()
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

int extractDate(std::string datestr, std::tm& date);