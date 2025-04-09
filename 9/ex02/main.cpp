/*
Requirements:
	- Program that takes positive ints as args
		- they come as separate args. not in one string
	- Special sort

Output:
	Before: 3 5 9 7 4
	After: 3 4 5 7 9
	Time to process a range of 5 elements with std::[..] : 0.00031 us
	Time to process a range of 5 elements with std::[..] : 0.00014 us
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <algorithm> // for std::sort

// Forbidden containers: std::map, std::stack
int main(int argc, char** argv)
{
	try
	{
		if (argc < 3)
			throw std::runtime_error("Program requires at least two arguments");

		std::vector<int> mainContainer;

		for (int i = 1; i < argc; ++i)
		{
			int value;
			std::istringstream iss(argv[i]);
			iss >> std::noskipws >> value;
			if (!iss.eof())
				throw std::runtime_error(std::string("Argument '") + argv[i] + "' contains trailing garbage");
			if (iss.fail())
				throw std::runtime_error(std::string("Argument '") + argv[i] + "' could not be converted to int");
			if (value < 0)
				throw std::runtime_error(std::string("Argument '") + argv[i] + "' is smaller than zero");
			mainContainer.push_back(value);
		}

		std::cout << "Before:";
		for (std::vector<int>::iterator it = mainContainer.begin(); it != mainContainer.end(); ++it)
			std::cout << " " << *it;
		std::cout << "\n";
		std::sort(mainContainer.begin(), mainContainer.end());
		std::cout << "After:";
		for (std::vector<int>::iterator it = mainContainer.begin(); it != mainContainer.end(); ++it)
			std::cout << " " << *it;
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}