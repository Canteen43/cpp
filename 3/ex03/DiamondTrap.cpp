#include <iostream>
#include "DiamondTrap.hpp"
// Default constructor
DiamondTrap::DiamondTrap()
{
	// Name, which is passed as parameter to a constructor
	name = "Nameless";
	// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
	ClapTrap::name = name + "_clap_name";
	// • Hit points (FragTrap)
	hitpoints = FragTrap::hitpoints;
	// • Energy points (ScavTrap)
	energy_points = ScavTrap::energy_points;
	// • Attack damage (FragTrap)
	attack_damage = FragTrap::attack_damage;

	std::cout << "DiamondTrap " << name << " called Default Constructor\n";
};
// Parametric Constructor:
DiamondTrap::DiamondTrap(std::string set_name)
{
	// Name, which is passed as parameter to a constructor
	name = set_name;
	// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
	ClapTrap::name = set_name + "_clap_name";
	// • Hit points (FragTrap)
	hitpoints = FragTrap::hitpoints;
	// • Energy points (ScavTrap)
	energy_points = ScavTrap::energy_points;
	// • Attack damage (FragTrap)
	attack_damage = FragTrap::attack_damage;

	std::cout << "DiamondTrap " << name << " called Parametric Constructor\n";
};
// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap " << name << " called Copy Constructor\n";
};
// Copy assignment operator:
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "DiamondTrap " << name << " called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " called Destructor\n";
};
// In addition to the special functions of both its parent classes, DiamondTrap will have
// its own special capacity:
// void whoAmI();
// This member function will display both its name and its ClapTrap name.
void DiamondTrap::whoAmI()
{
	std::cout << "Am I " << name << " or am I " << ClapTrap::name << "?\n";
};