#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\033[35mTesting construction and copying\033[0m\n";
	AForm Standard;
	std::cout << Standard;
	AForm topDog("Important", 1, 1);
	std::cout << topDog;
	Standard = topDog;
	std::cout << Standard;
	AForm highLevel(topDog);
	std::cout << highLevel;

	std::cout << "\n\033[35mTesting exceptions\033[0m\n";
	try
	{
		AForm tooSecret("Whoooa", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm tooTrivial("Idiot", 150, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Looser("Larry", 145);
		Looser.signAForm(topDog);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Winner("Wouter", 1);
		Winner.signAForm(highLevel);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}