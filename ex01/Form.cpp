#include "Form.hpp"

Form::Form(void) : _name("A-38"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src) : _name(src.getName()), _is_signed(src.getIsSigned()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute()) {}

Form& Form::operator=(const Form& rhs)
{
	this->_is_signed = rhs.getIsSigned();
	return *this;
}

Form::~Form(void) {}

const std::string&	Form::getName() const { return this->_name; }
bool	Form::getIsSigned() const { return this->_is_signed; }
int	Form::getGradeToSign() const { return this->_grade_to_sign; }
int	Form::getGradeToExecute() const { return this->_grade_to_execute; }

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw GradeTooLowException();
	this->_is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream&	operator<<(std::ostream& o, Form const& value)
{
	std::string	isSigned;
	
	isSigned = " is not signed.";
	if (value.getIsSigned())
		isSigned = " is signed.";
	o << value.getName() << isSigned << " It requires a bureaucrat grade " << value.getGradeToSign() << " or above to be signed and a bureaucrat grade " << value.getGradeToExecute() << " or above to be executed.";
	return o;
}

