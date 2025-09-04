# include "Intern.hpp"

int	main()
{
	Bureaucrat	paqui("Paqui", 1);
	Intern		someRandomIntern;
	AForm*		rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "garden");
	paqui.signForm(*rrf);
	(*rrf).execute(paqui);
	delete rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Pepe");
	paqui.signForm(*rrf);
	(*rrf).execute(paqui);
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Perico de los Palotes");
	paqui.signForm(*rrf);
	(*rrf).execute(paqui);
	delete rrf;
	rrf = someRandomIntern.makeForm("non existant form", "Perico");
}