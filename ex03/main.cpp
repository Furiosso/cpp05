# include "Intern.hpp"

int	main()
{
	Bureaucrat	paqui("Paqui", 1);
	Intern		someRandomIntern;
	AForm*		rrf;

	try
	{
		rrf = someRandomIntern.makeForm("shrubbery creation", "garden");
		paqui.signForm(*rrf);
		(*rrf).execute(paqui);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Pepe");
		paqui.signForm(*rrf);
		(*rrf).execute(paqui);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
	try
	{
		rrf = someRandomIntern.makeForm("presidential pardon", "Perico de los Palotes");
		paqui.signForm(*rrf);
		(*rrf).execute(paqui);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
	try
	{
		rrf = someRandomIntern.makeForm("non existant form", "Perico");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}