#include "Harl.hpp"
#include <string>
#include <iostream>


void Harl::debug( void )
{
	std::cout << "DEBUG:\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese"
		"-triple-pickle-special-ketchup burger. I really do!\n\n";
}
void Harl::info( void )
{
	std::cout << "INFO:\n";
	std::cout << "I cannot believe adding extra bacon costs more money."
		" You didn't put enough bacon in my burger!"
		" If you did, I wouldn't be asking for more!\n\n";
}
void Harl::warning( void )
{
	std::cout << "WARNING:\n";
	std::cout << "I think I deserve to have some extra bacon for free."
		" I've been coming for years whereas you started working here"
		" since last month.\n\n";
}
void Harl::error( void )
{
	std::cout << "ERROR:\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}
void Harl::complainWithFilter( std::string level )
{
	// Array of function pointers
	void (Harl::*functions[]) (void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	// Array of strings in same order as function pointers
	std::string strings[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	// Loop that checks for match between level and strings and saves index
	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if(level == strings[i])
		{
			index = i;
			break;
		}
	}

	// Switch statement with function call and fallthrough
	switch (index)
	{
		case 0:
			(this->*functions[0])();
			 /* fallthrough */
		case 1:
			(this->*functions[1])();
			 /* fallthrough */
		case 2:
			(this->*functions[2])();
			 /* fallthrough */
		case 3:
			(this->*functions[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}