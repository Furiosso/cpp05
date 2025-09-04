#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Intern::~Intern() {}

const char*	Intern::InvalidNameException::what() const throw()
{
	return "Requested form do no exist";
}

AForm*	Intern::makeForm(const std::string name, const std::string target) const
{
	std::string	forms[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int i;

	for (i = 0; i < 3; i++)
	{
		if (name == forms[i])
			break ;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw InvalidNameException();
	}
}
