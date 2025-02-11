#pragma once
#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		const std::string& getType() const;
		void setType(std::string newType);
		Weapon(std::string newType);
};