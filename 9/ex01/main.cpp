#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: exactly one argument expected.\n";
		return 1;
	}

	try
	{
		std::cout << RPN::calculate(argv[1]) << "\n";
		return 0;
	}
	catch(const std::exception& e)
	{
		// std::cerr << "Error" << e.what() <<"\n";
		std::cerr << "Error\n";
		return 1;
	}
}