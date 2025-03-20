#pragma once
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		// Default constructor
		ShrubberyCreationForm();
		// Parametric constructor
		ShrubberyCreationForm(std::string setTarget);
		// Copy constructor
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		// Copy assignment operator
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
		// Destructor
		~ShrubberyCreationForm();
		// ex02 execute function
		void execute(Bureaucrat const & executor) const;
};