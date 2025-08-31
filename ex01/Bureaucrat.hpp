#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();
		const std::string&	getName() const;
		int					getGrade() const;
		void				upgrade();
		void				downgrade();
		void				signForm(Form& form);
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& value);

#endif
