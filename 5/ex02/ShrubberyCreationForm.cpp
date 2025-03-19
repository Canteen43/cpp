#include "ShrubberyCreationForm.hpp"
// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery", 145, 137, "Aimless")
{};
// Parametric constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string setTarget)
: AForm("Shrubbery", 145, 137, setTarget)
{};
// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
: AForm(other)
{};
// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
};
// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm();
// ex02 execute function
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequierements();
	
};