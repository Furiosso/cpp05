#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
	public:
		Form();
		Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
		Form(const Form& src);
		Form& operator=(const Form& rhs);
		~Form();
		const std::string&	getName() const;
		bool				getIsSigned() const;
		const int			getGradeToSign() const;
		const int			getGradeToExecute() const;
};

std::ostream&	operator<<(std::ostream& o, Form const& value);

#endif
