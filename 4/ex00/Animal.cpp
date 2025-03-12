#include "Animal.hpp"
// Default constructor
Animal::Animal()
{
	std::cout << "Animal called Constructor\n";
};
// Copy constructor
Animal::Animal(const Animal& other)
{
	type = other.type;
	std::cout << "Animal called Copy Constructor\n";
};
// Copy assignment operator:
Animal& Animal::operator=(const Animal& other)
{
	type = other.type;
	std::cout << "Animal called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
Animal::~Animal()
{
	std::cout << "Animal called Destructor\n";
};
// Every animal must be able to use the member function:
// makeSound()
// It will print an appropriate sound (cats don’t bark).
void Animal::makeSound(void) const
{
	if (type.empty())
		std::cout << "*Generic Animal sound*\n";
	else if (type == "Cat")
		std::cout << "Meeoooooow\n";
	else if (type == "Dog")
		std::cout << "Wooof wooof\n";	
};
// Getter that is needed for main
const std::string Animal::getType(void) const
{
	return type;
};