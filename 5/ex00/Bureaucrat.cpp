#include "Bureaucrat.hpp"
// Default constructor
Bureaucrat::Bureaucrat()
: name("Nameless"), grade(150)
{};
// Parametric constructor
Bureaucrat::Bureaucrat(std::string set_name, int set_grade)
: name(set_name)
{
	if (set_grade > 150)
		throw GradeTooLowException();
	else if (set_grade < 1)
		throw GradeTooHighException();
	grade = set_grade;
};
// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat& other)
: name(other.name), grade(other.grade)
{};
// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	grade = other.grade;
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
// ex01 addition
void Bureaucrat::signForm(Form& formToSign)
{
	try
	{
		formToSign.beSigned(*this);
		std::cout << name << " signed " << formToSign.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << formToSign.getName() << " because " << e.what() << '\n';
	}
};


std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return lhs;
}