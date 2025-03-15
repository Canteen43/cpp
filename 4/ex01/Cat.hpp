#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		// Default constructor
		Cat();
		// Copy constructor
		Cat(const Cat& other);
		// Copy assignment operator:
		Cat& operator=(const Cat& other);
		// Destructor:
		~Cat();
		// Overriding makeSound() to make correct sound
		void makeSound(void) const;
		// setIdea function to test copy constructor and assignment
		void setIdea(const int index, const std::string string);
		// getIdea function to test copy constructor and assignment
		std::string getIdea(const int index) const;
};