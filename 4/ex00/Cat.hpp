#pragma once
#include "Animal.hpp"
class Cat : public Animal
{
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
};