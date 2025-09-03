#include "AForm.hpp"

AForm::AForm(void) : _name("A-38"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src.getName()), _is_signed(src.getIsSigned()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute()) {}

AForm& AForm::operator=(const AForm& rhs)
{
	this->_is_signed = rhs.getIsSigned();
	return *this;
}

AForm::~AForm(void) {}

const std::string&	AForm::getName() const { return this->_name; }
bool	AForm::getIsSigned() const { return this->_is_signed; }
int	AForm::getGradeToSign() const { return this->_grade_to_sign; }
int	AForm::getGradeToExecute() const { return this->_grade_to_execute; }

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw GradeTooLowException();
	this->_is_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char*	AForm::DocumentNotSigned::what() const throw()
{
	return "The document must be signed in order to be executed";
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!this->_is_signed)
		throw AForm::DocumentNotSigned();
	if (executor.getGrade() > this->_grade_to_execute)
		throw AForm::GradeTooLowException();
	executor.executeForm(*this);
}

std::ostream&	operator<<(std::ostream& o, AForm const& value)
{
	std::string	isSigned;
	
	isSigned = " is not signed.";
	if (value.getIsSigned())
		isSigned = " is signed.";
	o << value.getName() << isSigned << " It requires a bureaucrat grade " << value.getGradeToSign() << " or above to be signed and a bureaucrat grade " << value.getGradeToExecute() << " or above to be executed.";
	return o;
}

