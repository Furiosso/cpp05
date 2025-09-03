# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

int	main()
{
	Bureaucrat 				pepe("Pepe", 1);
	ShrubberyCreationForm	form1("home");
	PresidentialPardonForm	form2("Pepe Leches");
	RobotomyRequestForm		form3("Perro Sanchez");
	pepe.signForm(form1);
	form1.execute(pepe);
	pepe.signForm(form2);
	form2.execute(pepe);
	pepe.signForm(form3);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	RobotomyRequestForm		form4(form3);
	std::cout << "====From here is form4====" << std::endl;
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	RobotomyRequestForm	form5("Luis");
	RobotomyRequestForm	form6("Sergio");
	RobotomyRequestForm	form7("Marta");
	RobotomyRequestForm	form8("Ana");
	RobotomyRequestForm	form9("Alba");
	RobotomyRequestForm	formA("Pacomio");
	pepe.signForm(form5);
	form5.execute(pepe);
	pepe.signForm(form6);
	form6.execute(pepe);
	pepe.signForm(form7);
	form7.execute(pepe);
	pepe.signForm(form8);
	form8.execute(pepe);
	pepe.signForm(form9);
	form9.execute(pepe);
	pepe.signForm(formA);
	formA.execute(pepe);
}