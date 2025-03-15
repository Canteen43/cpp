#pragma once
#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		// Default constructor
		Brain();
		// Copy constructor
		Brain(const Brain& other);
		// Copy assignment operator:
		Brain& operator=(const Brain& other);
		// Destructor:
		~Brain();
		// setIdea function to test copy constructor and assignment
		void setIdea(const int index, const std::string string);
		// getIdea function to test copy constructor and assignment
		std::string getIdea(const int index) const;
};