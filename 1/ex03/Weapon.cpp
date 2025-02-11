#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	type = newType;
}

const std::string& Weapon::getType() const
{
	return type;
}
void Weapon::setType(std::string newType)
{
	type = newType;
}