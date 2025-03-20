#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// Default constructor
Intern::Intern()
{};
// Copy constructor
Intern::Intern(Intern& other)
{
	(void)other;
};
// Copy assignment operator
Intern& Intern::operator=(Intern& other)
{
	(void)other;
	return *this;
}
// Destructor
Intern::~Intern()
{};

// Static helper functions to create the different forms
static AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}
static AForm* createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

// makeForm()
AForm* Intern::makeForm(std::string form, std::string target)
{
	int formAmount = 3;
	std::string formList[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*functionList[]) (std::string str) =
	{
		createShrubbery,
		createRobotomy,
		createPresidential
	};
	
	for (int i = 0; i < formAmount; i++)
	{
		if (form == formList[i])
		{
			std::cout << "Intern creates " << form << "\n";
			return functionList[i](target);
		}
	}

	std::cout << "Intern could not create " << form << "\n";
	return NULL;
};