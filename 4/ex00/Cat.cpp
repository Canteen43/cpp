#include "Cat.hpp"
// Default constructor
Cat::Cat()
: Animal()
{
	type = "Cat";
	std::cout << "Cat called Constructor\n";
};
// Copy constructor
Cat::Cat(const Cat& other)
: Animal(other)
{
	std::cout << "Cat called Copy Constructor\n";
};
// Copy assignment operator:
Cat& Cat::operator=(const Cat& other)
{
	Animal::operator=(other);
	std::cout << "Cat called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
Cat::~Cat()
{
	std::cout << "Cat called Destructor\n";
};