#pragma once
#include <string>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		// Default constructor
		PresidentialPardonForm();
		// Parametric constructor
		PresidentialPardonForm(std::string setTarget);
		// Copy constructor
		PresidentialPardonForm(PresidentialPardonForm& other);
		// Copy assignment operator
		PresidentialPardonForm& operator=(PresidentialPardonForm& other);
		// Destructor
		~PresidentialPardonForm();
		// ex02 execute function
		void execute(Bureaucrat const & executor) const;
};