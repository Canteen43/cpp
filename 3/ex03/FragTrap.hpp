#pragma once
#include "ClapTrap.hpp"
class FragTrap : virtual public ClapTrap
{
	public:
	// Default constructor
	FragTrap();
	// Parametric Constructor:
	FragTrap(std::string set_name);
	// Copy constructor
	FragTrap(const FragTrap& other);
	// Copy assignment operator:
	FragTrap& operator=(const FragTrap& other);
	// Destructor:
	~FragTrap();
	// FragTrap has a special capacity too:
	// void highFivesGuys(void);
	// This member function displays a positive high fives request on the standard output.
	void highFivesGuys(void);
};