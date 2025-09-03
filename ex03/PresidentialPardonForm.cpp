#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon form", 25, 5), _target("Marvin") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("presidential pardon form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

const std::string&	PresidentialPardonForm::getTarget() const { return this->_target; }

void		PresidentialPardonForm::procede() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
