#pragma once
#include <string>
#include <iostream>
class Animal
{
	protected:
		std::string type;
	public:
		// Default constructor
		Animal();
		// Copy constructor
		Animal(const Animal& other);
		// Copy assignment operator:
		Animal& operator=(const Animal& other);
		// Destructor:
		~Animal();
		// Every animal must be able to use the member function:
		// makeSound()
		// It will print an appropriate sound (cats don’t bark).
		void makeSound(void) const;
		// Getter that is needed for main
		const std::string getType(void) const;
};