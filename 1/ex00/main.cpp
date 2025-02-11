#include "Zombie.hpp"
#include <iostream>




int main(void)
{
	std::cout << "Test 1: Stack zombie in main\n";
	std::cout << "Action: Created zombie 'Donald' in main and called announce()\n";
	std::cout << "Expected output: Constructor msg, announcement and no destructor msg for now\n";
	Zombie Donald("Donald");
	Donald.announce();
	std::cout << "\n\n";

	std::cout << "Test 2: Stack zombie in function\n";
	std::cout << "Action: Created zombie 'Elon' via randomChump()\n";
	std::cout << "Expected output: Constructor msg, announcement, destructor msg\n";
	randomChump("Elon");
	std::cout << "\n\n";

	std::cout << "Test 3: Heap zombie\n";
	std::cout << "Action: Created zombie 'JD' via newZombie(), called announc(), print 'Pause', delete Zombie\n";
	std::cout << "Expected output: Constructor msg, announcement, Pause, destructor msg\n";
	Zombie *jd = newZombie("JD");
	jd->announce();
	std::cout << "Pause\n";
	delete jd;
	std::cout << "\n\n";

	std::cout << "Test 1 appendix:\n";
	std::cout << "Action: 'Donald' will be automatically destroyed after main ends\n";
	std::cout << "Expected output: destructor msg\n";
}