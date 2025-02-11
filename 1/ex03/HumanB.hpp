#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		const Weapon* weapon;
	public:
		HumanB(std::string newName);
		void attack(void);
		void setWeapon(Weapon& newWeapon);
};