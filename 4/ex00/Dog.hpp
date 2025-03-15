#pragma once
#include "Animal.hpp"
class Dog : public Animal
{
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

};