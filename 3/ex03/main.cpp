#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
int main ()
{
	std::cout << "Testing construction:\n";
	FragTrap A("Sverry");
	FragTrap B(A);
	FragTrap C("Dingus");
	B = C;
	FragTrap D;

	std::cout << "\nTesting mandatory functions:\n";
	A.attack("your mom");
	B.beRepaired(10);
	C.highFivesGuys();

	std::cout << "\nShowing status after first round:\n";
	A.printStatus();
	B.printStatus();
	C.printStatus();
	D.printStatus();

	std::cout << "\nTesting destruction:\n";
}