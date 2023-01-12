#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(72, 45, "ShrubberyCreationForm"), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor" << std::endl;

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();
	
	std::ofstream file(this->_target + "_shrubbery");
	file << std::endl;
	file << "         # #### ####" << std::endl;
	file << "      ### \\/#|### |/####" << std::endl;
	file << "     ##\\/#/ \\||/##/_/##/_#" << std::endl;
	file << "   ###  \\/###|/ \\/ # ###" << std::endl;
	file << " ##_\\_#\\_\\## | #/###_/_####" << std::endl;
	file << "## #### # \\ #| /  #### ##/##" << std::endl;
	file << " __#_--###`  |{,###---###-~" << std::endl;
	file << "           \\ }{" << std::endl;
	file << "            }}{" << std::endl;
	file << "            }}{" << std::endl;
	file << "            {{}" << std::endl;
	file << "     , -=-~{ .-^- _" << std::endl;
	file << "           `}" << std::endl;
	file << "            {" << std::endl;
	file.close();
}