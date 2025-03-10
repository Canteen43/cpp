#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	hitpoints = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " called Default Constructor\n";
};
// Parametric Constructor:
ScavTrap::ScavTrap(std::string set_name) : ClapTrap(set_name)
{
	hitpoints = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " called Parametric Constructor\n";

};
// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
:	name(other.name),
	hitpoints(other.hitpoints),
	energy_points(other.energy_points),
	attack_damage(other.attack_damage)
{
	std::cout << "ScavTrap " << name << " called Copy Constructor\n";
};
// Copy assignment operator:
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	name = other.name;
	hitpoints = other.hitpoints;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << "ScavTrap " << name << " called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " called Destructor\n";
};
// Redefining attack (hides base class attack function):
void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << name;
	if (!hitpoints || !energy_points)
	{
		std::cout << " can't do anything because it has no energy or hitpoints\n";
		return;
	}
	std::cout << " attacks " << target << ", causing " << attack_damage 
		<< " points of damage!\n";
	energy_points--;
}
// ScavTrap will also have its own special capacity:
// void guardGate();
// This member function will display a message informing that ScavTrap is now in Gate
// keeper mode.
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
};