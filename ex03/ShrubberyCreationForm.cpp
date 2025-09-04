#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target(""), _filename("_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery creation", 145, 137), _target(target), _filename(_target + "_shrubbery") {}

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

const char*	ShrubberyCreationForm::FileNotOpened::what() const throw()
{
	return "File couldn't be opened";
}

void		ShrubberyCreationForm::procede() const
{
	std::ofstream	outfile;

	outfile.open(this->_filename.c_str());
	if (!outfile.is_open())
		throw FileNotOpened();
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
	<< "  \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	outfile.close();
}
