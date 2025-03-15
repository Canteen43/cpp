#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		// Default constructor
		Dog();
		// Copy constructor
		Dog(const Dog& other);
		// Copy assignment operator:
		Dog& operator=(const Dog& other);
		// Destructor:
		~Dog();
		// Overriding makeSound() to make correct sound
		void makeSound(void) const;
		// setIdea function to test copy constructor and assignment
		void setIdea(const int index, const std::string string);
		// getIdea function to test copy constructor and assignment
		std::string getIdea(const int index) const;
};