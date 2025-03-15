#include "Dog.hpp"
// Default constructor
Dog::Dog()
: Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog called Constructor\n";
};
// Copy constructor
Dog::Dog(const Dog& other)
: Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog called Copy Constructor\n";
};
// Copy assignment operator:
Dog& Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	*brain = *other.brain;
	std::cout << "Dog called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog called Destructor\n";
};
// Overriding makeSound() to make correct sound
void Dog::makeSound(void) const
{
	std::cout << "Wooof wooof\n";
};
// setIdea function to test copy constructor and assignment
void Dog::setIdea(const int index, const std::string string)
{
	brain->setIdea(index, string);
};
// getIdea function to test copy constructor and assignment
std::string Dog::getIdea(const int index) const
{
	std::string result;
	result = brain->getIdea(index);
	return result;
};