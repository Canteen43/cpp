#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		const Weapon& weapon;
	public:
		HumanA(std::string newName, Weapon& newWeapon);
		void attack(void);
};