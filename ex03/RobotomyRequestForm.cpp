#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_hasSuccess = true;

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), _target("Arthur Dent") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

const std::string&	RobotomyRequestForm::getTarget() const { return this->_target; }

void		RobotomyRequestForm::procede() const
{
	std::cout << "KRRRRRK SCREEEEEEEEEK KREEEEEEEEEEE" << std::endl;
	std::cout << this->_target;
	switch (_hasSuccess)
	{
		case true:
			std::cout << " was successfuly robotomized! :)";
			_hasSuccess = false;
			break;
		case false:
			std::cout << " failed to be robotomized :(";
			_hasSuccess = true;
			break ;
	}
	std::cout << std::endl;
}
