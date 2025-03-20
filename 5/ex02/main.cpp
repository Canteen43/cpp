#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat Franz("Franzy", 144);
	ShrubberyCreationForm shrubsAtScrubs("scrubs");
	Franz.signAForm(shrubsAtScrubs);
	Franz.executeForm(shrubsAtScrubs);

}