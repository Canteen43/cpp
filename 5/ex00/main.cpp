#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[35mTesting construction and copying\033[0m\n";
	Bureaucrat Biden;
	std::cout << Biden.getName() << ", " << Biden.getGrade() << "\n";
	Bureaucrat Hillary("Crooked", 1);
	std::cout << Hillary.getName() << ", " << Hillary.getGrade() << "\n";
	Biden = Hillary;
	std::cout << Biden.getName() << ", " << Biden.getGrade() << "\n";
	Bureaucrat Kamala(Hillary);
	std::cout << Kamala.getName() << ", " << Kamala.getGrade() << "\n";


}