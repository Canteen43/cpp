#include "Dog.hpp"
// Default constructor
Dog::Dog()
: Animal()
{
	type = "Dog";
	std::cout << "Dog called Constructor\n";
};
// Copy constructor
Dog::Dog(const Dog& other)
: Animal(other)
{
	std::cout << "Dog called Copy Constructor\n";
};
// Copy assignment operator:
Dog& Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	std::cout << "Dog called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
Dog::~Dog()
{
	std::cout << "Dog called Destructor\n";
};
// Overriding makeSound() to make correct sound
void Dog::makeSound(void) const
{
	std::cout << "Wooof wooof\n";	
};
