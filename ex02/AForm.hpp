#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
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
		class	DocumentNotSigned : public std::exception
		{
			const char* what() const throw();
		};
	protected:
		virtual void	procede() const = 0;
	public:
		AForm();
		AForm(const std::string name, const int grade_to_sign, const int grade_to_execute);
		AForm(const AForm& src);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm();
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat& bureaucrat);
		void				execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& o, AForm const& value);

#endif
