#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const _target;
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		virtual void execute(Bureaucrat const &executor) const;

};



#endif