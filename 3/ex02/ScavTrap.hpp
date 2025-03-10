#pragma once
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
	public:
	// Default constructor
	ScavTrap();
	// Parametric Constructor:
	ScavTrap(std::string set_name);
	// Copy constructor
	ScavTrap(const ScavTrap& other);
	// Copy assignment operator:
	ScavTrap& operator=(const ScavTrap& other);
	// Destructor:
	~ScavTrap();
	// Redefining attack (hides base class attack function):
	void attack(const std::string& target);
	// ScavTrap will also have its own special capacity:
	// void guardGate();
	// This member function will display a message informing that ScavTrap is now in Gate
	// keeper mode.
	void guardGate();
};