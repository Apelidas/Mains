#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(72, 45, "RobotomyRequestForm"), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor" << std::endl;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::cout << "*Drilling Noises*" << std::endl;
	srand((unsigned) time(NULL));

	if (rand() % 2 == 1)
		std::cout << this->_target << " has been succesfully robotomized" << std::endl;
	else
		std::cout << this->_target << " Robotomy went wrong" << std::endl;
}
