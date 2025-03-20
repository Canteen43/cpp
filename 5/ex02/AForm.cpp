#include "AForm.hpp"
// Default constructor
AForm::AForm()
: name("Nameless"), executingGrade(150), signingGrade(150), isSigned(false), target("Aimless")
{};
// Parametric constructor
AForm::AForm(std::string setName, int setSigningGrade, int setExecutingGrade, std::string setTarget)
{
	if (setSigningGrade > 150 || setExecutingGrade > 150)
		throw GradeTooLowException();
	else if (setSigningGrade < 1 || setExecutingGrade < 1)
		throw GradeTooHighException();
	executingGrade = setExecutingGrade;
	signingGrade = setSigningGrade;
	isSigned = false;
	name = setName;
	target = setTarget;
};
// Copy constructor
AForm::AForm(AForm& other)
: name(other.name),
  executingGrade(other.executingGrade),
  signingGrade(other.signingGrade),
  isSigned(other.isSigned),
  target(other.target)
{};
// Copy assignment operator
AForm& AForm::operator=(AForm& other)
{
	executingGrade = other.executingGrade;
	signingGrade = other.signingGrade;
	isSigned = other.isSigned;
	name = other.name;
	target = other.target;
	return *this;
}
// Destructor
AForm::~AForm()
{};
// Getters
std::string AForm::getName() const
{
	return name;
};
bool AForm::getIsSigned() const
{
	return isSigned;
};
int AForm::getSigningGrade() const
{
	return signingGrade;
};
int AForm::getExecutingGrade() const
{
	return executingGrade;
};
std::string AForm::getTarget() const
{
	return target;
};
// ex01 functions
void AForm::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() > signingGrade)
		throw GradeTooLowException();
	isSigned = true;
};
// ex02 functions
void AForm::checkExecutionRequierements(const Bureaucrat& executor) const
{
	if (executor.getGrade() > executingGrade)
		throw GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
}


std::ostream& operator<<(std::ostream& lhs, const AForm& rhs)
{
	lhs << rhs.getName()
		 << ": Required grades: sign "
		 << rhs.getSigningGrade()
		 << ", exec " << rhs.getExecutingGrade()
		 << ", Status: "
		 << rhs.getIsSigned()
		 << ", Target: "
		 << rhs.getTarget()
		 << ".\n";
	return lhs;
}