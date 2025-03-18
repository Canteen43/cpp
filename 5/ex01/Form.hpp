#pragma once
#include <string>
#include <exception>
#include <iostream>

class Form
{
	private:
		std::string name;
		bool isSigned;
		int	signingGrade;
		int executingGrade;
	public:
		// Default constructor
		Form();
		// Parametric constructor
		Form(std::string set_name, int set_grade); 
		// Copy constructor
		Form(Form& other);
		// Copy assignment operator
		Form& operator=(Form& other);
		// Destructor
		~Form();
		// Subject Requirements:
		std::string getName() const;
		bool getIsSigned() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;
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