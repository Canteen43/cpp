#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\033[35mTesting construction and copying\033[0m\n";
	Form Standard;
	std::cout << Standard;
	Form topDog("Important", 1, 1);
	std::cout << topDog;
	Standard = topDog;
	std::cout << Standard;
	Form highLevel(topDog);
	std::cout << highLevel;

	std::cout << "\n\033[35mTesting exceptions\033[0m\n";
	try
	{
		Form tooSecret("Whoooa", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form tooTrivial("Idiot", 150, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Looser("Larry", 145);
		Looser.signForm(topDog);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Winner("Wouter", 1);
		Winner.signForm(highLevel);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}