#include "ClapTrap.hpp"
#include <iostream>
// Default Constructor:
ClapTrap::ClapTrap()
:	name("Nameless"),
	hitpoints(10),
	energy_points(10),
	attack_damage(0)
{
	std::cout << "ClapTrap " << name << " called Constructor\n";
}
// Parametric Constructor:
ClapTrap::ClapTrap(std::string set_name)
:	name(set_name),
	hitpoints(10),
	energy_points(10),
	attack_damage(0)
{
	std::cout << "ClapTrap " << name << " called Constructor\n";
}
// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
:	name(other.name),
	hitpoints(other.hitpoints),
	energy_points(other.energy_points),
	attack_damage(other.attack_damage)
{
	std::cout << "ClapTrap " << name << " called Copy Constructor\n";
}
// Copy assignment operator:
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	name = other.name;
	hitpoints = other.hitpoints;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << "ClapTrap " << name << " called Copy Assignment Operator\n";
	return *this;
}
// Destructor:
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " called Destructor\n";
}
// Add the following public member functions so the ClapTrap looks more realistic:
// •void attack(const std::string& target);
void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name;
	if (!hitpoints || !energy_points)
	{
		std::cout << " can't do anything because it has no energy or hitpoints\n";
		return;
	}
	std::cout << " attacks " << target << ", causing " << attack_damage 
		<< " points of damage!\n";
	energy_points--;
}
// •void takeDamage(unsigned int amount);
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name;
	if (amount > hitpoints)
		amount = hitpoints;
	std::cout << " takes " << amount << " points of damage!\n";
	hitpoints -= amount;
}
// •void beRepaired(unsigned int amount);
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name;
	if (!hitpoints || !energy_points)
	{
		std::cout << " can't do anything because it has no energy or hitpoints\n";
		return;
	}
	std::cout << " repairs itself to gain " << amount << " hitpoints!\n";
	hitpoints += amount;
	energy_points--;
}
// Debug:
void ClapTrap::printStatus()
{
	std::cout << "Name: " << name
		<< ", Hitponts: " << hitpoints
		<< ", Energy Points: " << energy_points
		<< ", Attack Damage: " << attack_damage << "\n";
}