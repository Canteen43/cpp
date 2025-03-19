#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string name;
		int grade;
	public:
		// Default constructor
		Bureaucrat();
		// Parametric constructor
		Bureaucrat(std::string set_name, int set_grade); 
		// Copy constructor
		Bureaucrat(Bureaucrat& other);
		// Copy assignment operator
		Bureaucrat& operator=(Bureaucrat& other);
		// Destructor
		~Bureaucrat();
		// Subject Requirements:
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		// ex01 addition
		void signForm(Form& formToSign);
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
std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs);