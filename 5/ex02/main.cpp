#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Testing the AForm is truly virtual
	// AForm forbidden;
	{
	std::cout << "\033[4;37mTesting copy functions for ShrubberyCreationForm\033[0m\n";
	std::cout << "(Should work the same for all forms)\n";
	ShrubberyCreationForm nameless;
	std::cout << nameless;
	ShrubberyCreationForm foo("foo");
	std::cout << foo;
	nameless = foo;
	std::cout << nameless;
	Bureaucrat Andy("andy", 1);
	Andy.signAForm(foo);
	ShrubberyCreationForm bar(foo);
	std::cout << bar;
	}
	{
	std::cout << "\n\033[4;37mTesting functionality of ShrubberyCreationForm\033[0m\n";
	ShrubberyCreationForm shrubsAtScrubs("scrubs");
	Bureaucrat Franz("Franzy", 149);
	Franz.signAForm(shrubsAtScrubs);
	Franz.executeForm(shrubsAtScrubs);
	Bureaucrat Heinz("Heinzy", 144);
	Heinz.signAForm(shrubsAtScrubs);
	Heinz.executeForm(shrubsAtScrubs);
	Bureaucrat Ulrich("Ulli", 130);
	Ulrich.signAForm(shrubsAtScrubs);
	Ulrich.executeForm(shrubsAtScrubs);
	}
	{
	std::cout << "\n\033[4;37mTesting functionality of RobotomyRequestForm\033[0m\n";
	RobotomyRequestForm patientConsentForm("Neurolink patient");
	Bureaucrat Franz("Franzy", 75);
	Franz.signAForm(patientConsentForm);
	Franz.executeForm(patientConsentForm);
	Bureaucrat Heinz("Heinzy", 55);
	Heinz.signAForm(patientConsentForm);
	Heinz.executeForm(patientConsentForm);
	Bureaucrat Ulrich("Ulli", 40);
	Ulrich.signAForm(patientConsentForm);
	Ulrich.executeForm(patientConsentForm);
	}
	{
	std::cout << "\n\033[4;37mTesting functionality of PresidentialPardonForm\033[0m\n";
	PresidentialPardonForm safeYourself("Hunter Biden");
	Bureaucrat Franz("Franzy", 30);
	Franz.signAForm(safeYourself);
	Franz.executeForm(safeYourself);
	Bureaucrat Heinz("Heinzy", 13);
	Heinz.signAForm(safeYourself);
	Heinz.executeForm(safeYourself);
	Bureaucrat Biden("Joe", 3);
	Biden.signAForm(safeYourself);
	Biden.executeForm(safeYourself);
	}
}