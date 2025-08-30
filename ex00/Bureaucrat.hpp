#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class	Bureaucrat
{
	private:
		const std::string			_name;
		int							_grade;
		static const std::string	GradeTooHighException;
		static const std::string	GradeTooLowException;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat(void);
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				upgrade(void);
		void				downgrade(void);
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& value);

#endif
