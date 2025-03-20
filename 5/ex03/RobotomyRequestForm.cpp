#include "RobotomyRequestForm.hpp"
// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy", 72, 45, "Aimless")
{};
// Parametric constructor
RobotomyRequestForm::RobotomyRequestForm(std::string setTarget)
: AForm("Robotomy", 72, 45, setTarget)
{};
// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
: AForm(other)
{};
// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
};
// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{};
// ex02 execute function
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	// Checking if Form is signed and Bureaucrat grade is high enough
	checkExecutionRequierements(executor);

	std::cout << "Brrrr Dzzzzz Shrrrrrr\n.....\n";

	if (std::time(NULL) & 1)
		std::cout << getTarget() << " has been robotomized successfully\n";
	else
		std::cout << getTarget() << " could not be robotomized\n";
};