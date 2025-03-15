#include "Cat.hpp"
// Default constructor
Cat::Cat()
: Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat called Constructor\n";
};
// Copy constructor
Cat::Cat(const Cat& other)
: Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat called Copy Constructor\n";
};
// Copy assignment operator:
Cat& Cat::operator=(const Cat& other)
{
	Animal::operator=(other);
	*brain = *other.brain;
	std::cout << "Cat called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat called Destructor\n";
};
// Overriding makeSound() to make correct sound
void Cat::makeSound(void) const
{
	std::cout << "Meeoooooow\n";
};
// setIdea function to test copy constructor and assignment
void Cat::setIdea(const int index, const std::string string)
{
	brain->setIdea(index, string);
};
// getIdea function to test copy constructor and assignment
std::string Cat::getIdea(const int index) const
{
	std::string result;
	result = brain->getIdea(index);
	return result;
};