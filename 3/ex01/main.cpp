#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
int main ()
{
	std::cout << "Testing construction:\n";
	ScavTrap A("Sverry");
	ScavTrap B(A);
	ScavTrap C("Dingus");
	B = C;
	ScavTrap D;

	std::cout << "\nTesting mandatory functions:\n";
	A.attack("your mom");
	B.beRepaired(10);
	C.guardGate();

	std::cout << "\nShowing status after first round:\n";
	A.printStatus();
	B.printStatus();
	C.printStatus();

	std::cout << "\nTesting destruction:\n";
}