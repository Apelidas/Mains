#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		AForm *Shrubbery(std::string target);
		AForm *Pardon(std::string target);
		AForm *Robotomy(std::string target);
		AForm *makeForm(std::string name, std::string target);
};

#endif