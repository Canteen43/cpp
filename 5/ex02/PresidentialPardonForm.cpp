#include "PresidentialPardonForm.hpp"
// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential", 25, 5, "Aimless")
{};
// Parametric constructor
PresidentialPardonForm::PresidentialPardonForm(std::string setTarget)
: AForm("Presidential", 25, 5, setTarget)
{};
// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
: AForm(other)
{};
// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
};
// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{};
// ex02 execute function
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	// Checking if Form is signed and Bureaucrat grade is high enough
	checkExecutionRequierements(executor);

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
};