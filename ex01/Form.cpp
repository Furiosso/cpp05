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
const int	Form::getGradeToSign() const { return this->_grade_to_sign; }
const int	Form::getGradeToExecute() const { return this->_grade_to_execute; }
std::ostream&	operator<<(std::ostream& o, Form const& value)
{
	o << value;
	return o;
}

