#include "Brain.hpp"
// Default constructor
Brain::Brain()
{
	std::cout << "Brain called Constructor\n";
};
// Copy constructor
Brain::Brain(const Brain& other)
{
	for (int i = 0; i <= 99; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain called Copy Constructor\n";
};
// Copy assignment operator:
Brain& Brain::operator=(const Brain& other)
{
	for (int i = 0; i <= 99; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain called Copy Assignment Operator\n";
	return *this;
};
// Destructor:
Brain::~Brain()
{
	std::cout << "Brain called Destructor\n";
};
// setIdea function to test copy constructor and assignment
void Brain::setIdea(const int index, const std::string string)
{
	if (index < 0 || index > 99)
		return;
	ideas[index] = string;
};
// getIdea function to test copy constructor and assignment
std::string Brain::getIdea(const int index) const
{
	std::string result;
	if (index < 0 || index > 99)
		return result;
	result = ideas[index];
	return result;
};