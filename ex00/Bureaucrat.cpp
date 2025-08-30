#include "Bureaucrat.hpp"

const std::string	Bureaucrat::GradeTooHighException = "Error: Grade too high!";
const std::string	Bureaucrat::GradeTooLowException = "Error: Grade too low!";

Bureaucrat::Bureaucrat(void) : _name("Pepe"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade == 0)
		throw GradeTooHighException;
	if (grade > 150)
		throw GradeTooLowException;
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	const_cast<std::string&>(this->_name) = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

void	Bureaucrat::upgrade(void)
{
	this->_grade--;
}

const std::string&	Bureaucrat::getName(void) const { return this->_name; }

int	Bureaucrat::getGrade(void) const { return this->_grade; }

void	Bureaucrat::downgrade(void)
{
	this->_grade++;
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& value)
{
	o << value.getName() << ", bureaucrat grade " << value.getGrade();
	return o;
}
