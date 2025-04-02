#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		const int executingGrade;
		const int signingGrade;
		bool isSigned;
	public:
		// Default constructor
		Form();
		// Parametric constructor
		Form(std::string setName, int setSigningGrade, int setExecutingGrade);
		// Copy constructor
		Form(Form& other);
		// Copy assignment operator
		Form& operator=(Form& other);
		// Destructor
		~Form();
		// Getters
		std::string getName() const;
		bool getIsSigned() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;
		// More subject functions
		void beSigned(Bureaucrat& signer);
		// Custom exceptions
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return "Grade too high!";
			}
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return "Grade too low!";
			}
		};
};
std::ostream& operator<<(std::ostream& lhs, const Form& rhs);