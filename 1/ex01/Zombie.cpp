#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie()
{
	std::cout << GREEN << "Constructor called. Createad nameless Zombie\n" << RESET;
}
Zombie::~Zombie()
{
	std::cout << RED <<"Destructor called for Zombie " << name << "\n" << RESET;
}
void Zombie::announce( void )
{
	std::cout << YELLOW << name << ": BraiiiiiiinnnzzzZ...\n" << RESET;
}
void Zombie::setName(std::string newName)
{
	name = newName;
	std::cout << BLUE << "Nameless zombie was named '" << newName << "'\n" << RESET;
}