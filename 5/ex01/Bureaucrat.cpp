#include "Bureaucrat.hpp"
// Default constructor
Bureaucrat::Bureaucrat()
: name("Nameless"), grade(150)
{};
// Parametric constructor
Bureaucrat::Bureaucrat(std::string set_name, int set_grade)
{
	if (set_grade > 150)
		throw GradeTooLowException();
	else if (set_grade < 1)
		throw GradeTooHighException();
	grade = set_grade;
	name = set_name;
};
// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat& other)
: name(other.name), grade(other.grade)
{};
// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	grade = other.grade;
	name = other.name;
	return *this;
}
// Destructor
Bureaucrat::~Bureaucrat()
{};
// Subject requirements
std::string Bureaucrat::getName() const
{
	return name;
};
int Bureaucrat::getGrade() const
{
	return grade;
};
void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
};
void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
};
std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return lhs;
}