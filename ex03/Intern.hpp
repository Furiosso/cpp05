#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		class InvalidNameException : public std::exception
		{
			const char* what() const throw();
		};
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& rhs);
		~Intern();
		AForm*	makeForm(const std::string name, const std::string target) const;
};

#endif
