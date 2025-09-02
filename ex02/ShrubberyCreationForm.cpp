#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("A-38", 145, 137)
{}



ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
{
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::ostream&	operator<<(std::ostream& o, ShrubberyCreationForm const& value)
{
	o << value;
	return o;
}

