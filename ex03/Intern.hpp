#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& rhs);
		~Intern();
		AForm*	makeForm(std::string name, std::string target);
};

#endif
