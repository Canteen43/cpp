#include "Form.hpp"
// Default constructor
Form::Form()
: name("Nameless"), executingGrade(150), signingGrade(150), isSigned(false)
{};
// Parametric constructor
Form::Form(std::string setName, int setSigningGrade, int setExecutingGrade)
: name(setName), executingGrade(setExecutingGrade), signingGrade(setSigningGrade)
{
	if (setSigningGrade > 150 || setExecutingGrade > 150)
		throw GradeTooLowException();
	else if (setSigningGrade < 1 || setExecutingGrade < 1)
		throw GradeTooHighException();
	isSigned = false;
};
// Copy constructor
Form::Form(Form& other)
: name(other.name), executingGrade(other.executingGrade), signingGrade(other.signingGrade), isSigned(other.isSigned)
{};
// Copy assignment operator
Form& Form::operator=(Form& other)
{
	isSigned = other.isSigned;
	return *this;
}
// Destructor
Form::~Form()
{};
// Getters
std::string Form::getName() const
{
	return name;
};
bool Form::getIsSigned() const
{
	return isSigned;
};
int Form::getSigningGrade() const
{
	return signingGrade;
};
int Form::getExecutingGrade() const
{
	return executingGrade;
};
// More subject functions
void Form::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() > signingGrade)
		throw GradeTooLowException();
	isSigned = true;
};
std::ostream& operator<<(std::ostream& lhs, const Form& rhs)
{
	lhs << rhs.getName() << ": Required grades: sign " << rhs.getSigningGrade() << ", exec " << rhs.getExecutingGrade() << ", Status: " << rhs.getIsSigned() << ".\n";
	return lhs;
}