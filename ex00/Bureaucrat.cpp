#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Marvin"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const { return this->_name; }

int	Bureaucrat::getGrade() const { return this->_grade; }

void	Bureaucrat::upgrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::downgrade()
{

	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& value)
{
	o << value.getName() << ", bureaucrat grade " << value.getGrade();
	return o;
}
