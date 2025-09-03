#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern& rhs)
{
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::makeForm(std::string name, std::string target)
{

}
