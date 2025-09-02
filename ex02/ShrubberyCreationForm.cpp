#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubb-Form", 145, 137), _target(target)
{
	this->_filename = this->_target.append("_shrubbery").c_str();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src.getTarget()), _filename(src.getFileName()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs.getTarget();
		this->_filename = rhs.getFileName();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

const std::string&	ShrubberyCreationForm::getTarget() const { return this->_target; }

const std::string&	ShrubberyCreationForm::getFileName() const { return this->_filename; }

void		ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() < this->getGradeToExecute())
	{
	std::ofstream	outfile;

	outfile.open(this->_filename.c_str());
	if (!outfile.is_open())
		std::cerr << "Couldn't create file" << std::endl;
	
    outfile << std::endl
	<< "           ,@@@@@@@," << std::endl
    << "   ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
    << ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
	<< ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
	<< "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
	<< "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
	<< "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
    << "   	|o|        | |         | |" << std::endl
    << "    |.|        | |         | |" << std::endl
	<< "  \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	outfile.close();
	}
}
