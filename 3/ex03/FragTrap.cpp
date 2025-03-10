#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
// Default constructor
FragTrap::FragTrap()
: ClapTrap()
{
	hitpoints = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " called Default Constructor\n";
};
// Parametric Constructor:
FragTrap::FragTrap(std::string set_name)
: ClapTrap(set_name)
{
	hitpoints = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " called Parametric Constructor\n";

};
// Copy constructor
FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other)
{
	std::cout << "FragTrap " << name << " called Copy Constructor\n";
};
// Copy assignment operator:
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << name << " called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " called Destructor\n";
};
// FragTrap has a special capacity too:
// void highFivesGuys(void);
// This member function displays a positive high fives request on the standard output.
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " positively requests a high five!\n";
};