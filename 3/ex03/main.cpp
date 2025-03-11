#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
int main ()
{
	std::cout << "Testing construction:\n";
	DiamondTrap A("Sverry");
	DiamondTrap B(A);
	DiamondTrap C("Dingus");
	B = C;
	DiamondTrap D;

	std::cout << "\nTesting mandatory functions:\n";
	A.attack("your mom");
	B.beRepaired(10);
	C.highFivesGuys();
	D.guardGate();

	std::cout << "\nShowing status after first round:\n";
	A.printStatus();
	A.whoAmI();
	B.printStatus();
	B.whoAmI();
	C.printStatus();
	C.whoAmI();
	D.printStatus();
	D.whoAmI();

	std::cout << "\nTesting destruction:\n";
}