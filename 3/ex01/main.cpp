#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
int main ()
{
	// std::cout << "Testing construction:\n";
	// ClapTrap A("Sverry");
	// ClapTrap B(A);
	// ClapTrap C("Dingus");
	// B = C;

	// std::cout << "\nTesting mandatory functions:\n";
	// A.attack("your mom");
	// B.beRepaired(10);
	// C.takeDamage(5);

	// std::cout << "\nShowing status after first round:\n";
	// A.printStatus();
	// B.printStatus();
	// C.printStatus();

	// std::cout << "\nTesting overflow:\n";
	// A.takeDamage(30);
	// for (int i = 0; i < 15; i++)
	// {
	// 	B.attack("your sister");
	// }

	// std::cout << "\nTesting destruction:\n";
	std::cout << "Testing construction:\n";
	ScavTrap Test1;
	std::cout << "\nEnd of test!\n";
	return 0;
}