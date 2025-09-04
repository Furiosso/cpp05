#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		std::string	_filename;
		class	FileNotOpened : public std::exception
		{
			const char* what() const throw();
		};
		void				procede() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm(void);
		const std::string&	getTarget() const;
		const std::string&	getFileName() const;
};

#endif
