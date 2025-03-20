#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Bender");

	AForm* nvf;
	nvf = someRandomIntern.makeForm("bla bla", "Bender");

	Bureaucrat topDog("Obama", 1);
	topDog.signAForm(*rrf);
	topDog.executeForm(*rrf);
	topDog.signAForm(*ppf);
	topDog.executeForm(*ppf);
	topDog.signAForm(*scf);
	topDog.executeForm(*scf);
	// topDog.signAForm(*nvf);

	delete rrf;
	delete ppf;
	delete scf;
}