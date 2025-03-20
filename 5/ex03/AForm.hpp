#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string name;
		int executingGrade;
		int	signingGrade;
		bool isSigned;
		std::string target;
	public:
		// Default constructor
		AForm();
		// Parametric constructor
		AForm(std::string setName, int setSigningGrade, int setExecutingGrade, std::string setTarget);
		// Copy constructor
		AForm(AForm& other);
		// Copy assignment operator
		AForm& operator=(AForm& other);
		// Destructor
		virtual ~AForm();
		// Getters
		std::string getName() const;
		bool getIsSigned() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;
		std::string getTarget() const;
		// More subject functions
		void beSigned(Bureaucrat& signer);
		// ex02 functions
		virtual void execute(Bureaucrat const & executor) const = 0;
		void checkExecutionRequierements(const Bureaucrat& executor) const;
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
		class FormNotSignedException : public std::exception
		{
			const char* what() const throw()
			{
				return "Form not signed!";
			}
		};
};
std::ostream& operator<<(std::ostream& lhs, const AForm& rhs);