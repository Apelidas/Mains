#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm *Intern::Shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::Robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::Pardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string arr[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	AForm *(Intern::*fptr[3])(std::string) = {&Intern::Shrubbery, &Intern::Pardon, &Intern::Robotomy};

	for (int i = 0; i < 4; i++)
	{
		if (arr[i].compare(name) == 0)
		{
			std::cout << "Intern creates Form " << name << std::endl;
			return ((this->*fptr[i])(target));
		}
	}
	std::cout << "The Intern made Coffee, because he didn´t know about the " << name << std::endl;
	return (NULL);
}