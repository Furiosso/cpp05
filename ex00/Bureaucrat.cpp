#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
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
	o << value.getName() << ", bureaucrat grade " << value.getGrade() << std::endl;
	return o;
}

