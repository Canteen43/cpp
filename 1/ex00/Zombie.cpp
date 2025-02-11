#include "Zombie.hpp"
#include <iostream>

void Zombie::announce( void )
{
	std::cout << YELLOW << name << ": BraiiiiiiinnnzzzZ...\n" << RESET;
}

Zombie::Zombie(std::string given_name)
{
	name = given_name;
	std::cout << GREEN << "Constructor called for Zombie " << name << "\n" << RESET;
}
Zombie::~Zombie()
{
	std::cout << RED <<"Destructor called for Zombie " << name << "\n" << RESET;
}