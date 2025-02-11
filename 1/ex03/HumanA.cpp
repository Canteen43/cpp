#include <iostream>

#include "HumanA.hpp"
HumanA::HumanA(std::string newName, Weapon& newWeapon) : name(newName), weapon(newWeapon)
{}
void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}