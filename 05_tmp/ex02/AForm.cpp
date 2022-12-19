#include "AForm.hpp"

AForm::AForm(): _name("Passierschein A38"), _signed(false) , _gradeSign(150), _gradeExec(150)
{
	std::cout << "AForm Default Constructor" << std::endl;
}

AForm::AForm(int gradeSign, int gradeExec, std::string name): _name(name), _signed(false) , _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "AForm Fully Variable Constructor" << std::endl;
}

AForm::AForm(AForm &copy): _name(copy._name), _signed(copy._signed) , _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "Form Copy Constructor Constructor" << std::endl;
}

AForm& AForm::operator=(AForm &copy)
{
	this->_signed = copy._signed;
	return(*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor" << std::endl;
}

std::string const AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

void AForm::beSigned(Bureaucrat const&toSign)
{
	if (toSign.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade is NOT High enough!");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Exception: The Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, AForm const &read)
{
	out << "AForm:\t\t" << read.getName() << std::endl;
	out << "Is Signed:\t" << read.getSigned() << std::endl;
	out << "Grade toSign:\t" << read.getGradeSign() << std::endl;
	out << "Grade toExec:\t" << read.getGradeExec() << std::endl;
	return (out);
}


