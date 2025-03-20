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
ShrubberyCreationForm::~ShrubberyCreationForm()
{};
// ex02 execute function
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	// Checking if Form is signed and Bureaucrat grade is high enough
	checkExecutionRequierements(executor);

	// Opening file to read from (contains tree ASCII art)
	std::ifstream infile("ShrubberySource.txt");
	if (!infile)
		throw std::runtime_error("Opening infile failed!");

	// Opening file to write to
	std::string outfile_name = getTarget() + "_shrubbery";
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile)
		throw std::runtime_error("Opening outfile failed!");
	
	// Copying contents
	outfile << infile.rdbuf();
};