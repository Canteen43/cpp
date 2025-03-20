#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		// Default constructor
		Intern();
		// Copy constructor
		Intern(Intern& other);
		// Copy assignment operator
		Intern& operator=(Intern& other);
		// Destructor
		~Intern();
		// makeForm()
		AForm* makeForm(std::string form, std::string target);
};