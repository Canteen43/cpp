#include "Zombie.hpp"
#include <iostream>

#define HORDESIZE 11


int main(void)
{
	std::cout << "Test 1: Zombie Horde creation\n";
	std::cout << "Action: Created zombie horde of HORDESIZE Donalds\n";
	std::cout << "Expected output: HORDESIZE constr. msg, HORDESIZE name set msg.,\n";
	Zombie *horde = zombieHorde(HORDESIZE, "Donald");
	std::cout << "\n\n";

	std::cout << "Test 2: Zombie horde announcment\n";
	std::cout << "Action: Iterating through zombie horde for announcement\n";
	std::cout << "Expected output: HORDESIZE announcement msg.\n";
	for (int i = 0; i < HORDESIZE; i++)
		horde[i].announce();
	std::cout << "\n\n";

	std::cout << "Test 3: Horde destruction\n";
	std::cout << "Action: Destroying horde by calling delete on horde array\n";
	std::cout << "Expected output: HORDESIZE destr. msg\n";
	if (HORDESIZE > 0)
		delete[] horde;
}