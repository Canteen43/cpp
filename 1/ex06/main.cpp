#include <iostream>
#include "Harl.hpp"

int main (int argc, char **argv)
{
	// Checking argument nbr
	if (argc != 2)
	{
		std::cerr << "harlFilter only accepts exactly one argument :)\n";
		return (1);
	}
	
	// Altered complain function
	Harl().complainWithFilter(argv[1]);
	
}