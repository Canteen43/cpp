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
	// Checking datestr and converting it to std::tm date
	std::string datestr = line.substr(0, 10);
	std::tm date;
	if (extractDate(datestr, date) == -1)
	{
		std::ostringstream errorMessage;
		errorMessage << "Error: bad input => " << datestr;
		return errorMessage.str();
	}
	// Showing the date that was extracted
	// std::cout << std::asctime(&date);

	// Checking middlestr
	if (line.size() <= 10)
		return "Error: line too short.";
	std::string middlestr = line.substr(10, 3);
	if (middlestr != " | ")
		return "Error: ' | ' is not in correct place";

	// Checking valuestr
	if (line.size() <= 13)
		return "Error: line too short.";
	std::string valuestr = line.substr(13);
	double value;
	std::istringstream iss(valuestr);
	iss >> std::noskipws >> value;
	if (!iss.eof())
		return "Error: value contained trailing garbage.";
	if (iss.fail())
		return "Error: value could not be converted.";
	if (value < 0)
		return "Error: not a positive number.";
	if (value < 0 || value > 1000)
		return "Error: too large a number.";

	// - to find the equal of lower date, I can use upper_bound and --it
	// - if the iterator equals rend() than there is no lower key, otherwise the iterator will be right
	std::map<std::tm, double>::iterator it = container.upper_bound(date);
	if (it == container.begin())
		return "Error: bitcoin wasn't a thing then.";
	--it;

	// Preparing line to return
	std::ostringstream oss;
	oss << datestr << " => " << value << " = " << value * it->second;
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

bool isFormatted(const char* format, const char* string)
{
	if (strlen(format) != strlen(string))
		return false;

	for(int i = 0; format[i]; ++i)
	{
		if (format[i] == 'd' && (string[i] < '0' || string[i] > '9'))
			return false;
		if (format[i] != 'd' && format[i] != string[i])
			return false;
	}

	return true;
}

bool isValidDate(std::tm date)
{
	// Checking if date is in safe range 1970 to 2038
	if (date.tm_year + 1900 < 1970 || date.tm_year + 1900 >= 2038)
		return false;

	// Using mktime for 1) conversion to time_t, 2) normalizing date
	// 1) Converting date to time_t t and checking that date is not in the future
	std::tm temp = date;
	time_t t = mktime(&temp);
	if (t > std::time(NULL))
		return false;
	// 2) Comparing if normalized date is equal to provided date. If not the provided date was false
	if(temp.tm_year != date.tm_year ||
		temp.tm_mon != date.tm_mon ||
		temp.tm_mday != date.tm_mday)
		return false;

	return true;
}

int extractDate(std::string datestr, std::tm& date)
{
	// Checking for right format
	if (!isFormatted("dddd-dd-dd", datestr.c_str()))
		return -1;

	// Setting date to zero
	std::memset(&date, 0, sizeof(date));

	// Extracting date
	sscanf(datestr.c_str(), "%d-%d-%d", &date.tm_year, &date.tm_mon, &date.tm_mday);

	// Converting to proper std::tm
	date.tm_year -= 1900;
	date.tm_mon -= 1;

	// Checking if date is valid
	if (!isValidDate(date))
		return -1;

	return 0;
}
