#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: program requires exactly one argument.\n";
		return 1;
	}
	
	std::fstream infile(argv[1]);
	if (!infile)
	{
		std::cerr << "Error: could not open input file.\n";
		return 1;
	}

	// Instance of the BitcoinExchange for importing .csv file and converting input file lines
	BitcoinExchange exchanger;

	std::string line;
	std::getline(infile, line);
	if (line != "date | value")
	{
		std::cerr << "Error: first line of input file must be 'date | value'.\n";
		return 1;
	}
	while (std::getline(infile, line))
	{
		std::cout << exchanger.convertLine(line) << "\n";
	}

	infile.close();

	return 0;
}
/*
PROBLEM: Using std::tm does not work for a key!


Process:
Step1: Open infile
Step2: Read csv file
	- instantiate BitcoinExchange
	- pass the name of the .csv file to loadCSV()
Step3: Call Bitcoin Exchange for each line

Ideas:
- since the .csv file is the data base and not the input file, i conclude that parsing can be strict
	- skip first line
	- split around the comma
	- convert datestring to struct tm
	- convert numberstr to float
	- error if conversion error
- infile parsing has to be more robust
	- split around " | "
	- check that first line contains "date | value"
	- check that value does not have garbage inside and is a float between 0 and 1000\
	- have specific error messages for each case
*/