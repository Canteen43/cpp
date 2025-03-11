#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
	std::string name;
	public:
	// Default constructor
	DiamondTrap();
	// Parametric Constructor:
	DiamondTrap(std::string set_name);
	// Copy constructor
	DiamondTrap(const DiamondTrap& other);
	// Copy assignment operator:
	DiamondTrap& operator=(const DiamondTrap& other);
	// Destructor:
	~DiamondTrap();
	// • attack() (Scavtrap)
	using ScavTrap::attack;
	// In addition to the special functions of both its parent classes, DiamondTrap will have
	// its own special capacity:
	// void whoAmI();
	// This member function will display both its name and its ClapTrap name.
	void whoAmI();
};