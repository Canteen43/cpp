#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\033[35mTesting construction and copying\033[0m\n";
	Bureaucrat Biden;
	std::cout << Biden;
	Bureaucrat Hillary("Crooked", 1);
	std::cout << Hillary;
	Biden = Hillary;
	std::cout << Biden;
	Bureaucrat Kamala(Hillary);
	std::cout << Kamala;

	std::cout << "\n\033[35mTesting exceptions\033[0m\n";
	try
	{
		Biden.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat workerUSAID;
	try
	{
		workerUSAID.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Elon("Elon", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat workerUSAIDhowElonSeesThem("Idiot", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}