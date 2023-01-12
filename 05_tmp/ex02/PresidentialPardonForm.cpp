#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(25, 5, "PresidentialPardonForm"), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor" << std::endl;

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else
		std::cout << "We hereby inform you that " << this->_target << " has been pardoned by the Spaghetti Monster" << std::endl;
}

