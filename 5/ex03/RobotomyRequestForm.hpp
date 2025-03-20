#pragma once
#include <string>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		// Default constructor
		RobotomyRequestForm();
		// Parametric constructor
		RobotomyRequestForm(std::string setTarget);
		// Copy constructor
		RobotomyRequestForm(RobotomyRequestForm& other);
		// Copy assignment operator
		RobotomyRequestForm& operator=(RobotomyRequestForm& other);
		// Destructor
		~RobotomyRequestForm();
		// ex02 execute function
		void execute(Bureaucrat const & executor) const;
};