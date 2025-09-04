# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

int	main()
{
	Bureaucrat 				tono("Toño", 140);
	Bureaucrat 				paqui("Paqui", 50);
	Bureaucrat 				lucas("Lucas", 20);
	Bureaucrat 				pepi("Pepi", 1);
	ShrubberyCreationForm	form1("home");
	PresidentialPardonForm	form2("Pepe Leches");
	RobotomyRequestForm		form3("Perico de los Palotes");
	RobotomyRequestForm		form4(form3);
	RobotomyRequestForm		form5("Diodoro");
	RobotomyRequestForm		form6("Tertuliano");
	RobotomyRequestForm		form7("Ireneo");
	RobotomyRequestForm		form8("Cipriano");
	RobotomyRequestForm		form9("Nestoriano");
	RobotomyRequestForm		formA("Pacomio");

	std::cout << "==== Shrubbery Creation ====" << std::endl;
	tono.executeForm(form1);
	tono.signForm(form1);
	tono.executeForm(form1);
	paqui.executeForm(form1);
	std::cout << "==== Presidential Pardon ====" << std::endl;
	lucas.executeForm(form2);
	lucas.signForm(form2);
	lucas.executeForm(form2);
	pepi.executeForm(form2);
	std::cout << "==== Robotomy Request ====" << std::endl;
	paqui.executeForm(form3);
	paqui.signForm(form3);
	paqui.executeForm(form3);
	lucas.executeForm(form3);
	std::cout << "==== From here on is form4 ====" << std::endl;
	lucas.signForm(form4);
	lucas.executeForm(form4);
	lucas.executeForm(form4);
	lucas.executeForm(form4);
	lucas.executeForm(form4);
	lucas.executeForm(form4);
	lucas.executeForm(form4);
	std::cout << "==== Testing executing different Robotomy Requests in a row ====" << std::endl;
	lucas.signForm(form5);
	lucas.executeForm(form5);
	lucas.signForm(form6);
	lucas.executeForm(form6);
	lucas.signForm(form7);
	lucas.executeForm(form7);
	lucas.signForm(form8);
	lucas.executeForm(form8);
	lucas.signForm(form9);
	lucas.executeForm(form9);
	lucas.signForm(formA);
	lucas.executeForm(formA);
}