#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	pepe;
		std::cout << pepe << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
	try
	{
		Bureaucrat	charo("Charo", 42);
		std::cout << charo << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
	try
	{
		Bureaucrat	luis("Luis", 156);
		std::cout << luis;
	}
	catch(const std::string& e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
	try
	{
		Bureaucrat	nano("Nano", 0);
		std::cout << nano;
	}
	catch(const std::string& e)
	{
		std::cerr << "Exception: " << e << std::endl;
	}
}
