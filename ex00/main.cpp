#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	marvin;
		std::cout << marvin << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	charo("Charo", 42);
		std::cout << charo << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	luis("Luis", 156);
		std::cout << luis << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	nano("Nano", 0);
		std::cout << nano << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	nacho("Nacho", 150);
		std::cout << nacho << std::endl;
		nacho.upgrade();
		std::cout << nacho << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	brenda("Brenda", 1);
		std::cout << brenda << std::endl;
		brenda.downgrade();
		std::cout << brenda << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	lina("Lina", 1);
		std::cout << lina << std::endl;
		lina.upgrade();
		std::cout << lina << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	paqui("Paqui", 150);
		std::cout << paqui << std::endl;
		paqui.downgrade();
		std::cout << paqui << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
