#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
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
