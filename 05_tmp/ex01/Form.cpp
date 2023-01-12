#include "Form.hpp"

Form::Form(): _name("Passierschein A38"), _signed(false) , _gradeSign(150), _gradeExec(150)
{
	std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(int gradeSign, int gradeExec, std::string name): _name(name), _signed(false) , _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Form Fully Variable Constructor" << std::endl;
}

Form::Form(Form &copy): _name(copy._name), _signed(copy._signed) , _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "Form Copy Constructor Constructor" << std::endl;
}

Form& Form::operator=(Form &copy)
{
	this->_signed = copy._signed;
	return(*this);
}

Form::~Form()
{
	std::cout << "Form Destructor" << std::endl;
}

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int Form::getGradeExec() const
{
	return (this->_gradeExec);
}

void Form::beSigned(Bureaucrat const&toSign)
{
	if (toSign.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	this->_signed = true;
}


const char * Form::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade is NOT High enough!");
}

std::ostream &operator<<(std::ostream &out, Form const &read)
{
	out << "Form:\t\t" << read.getName() << std::endl;
	out << "Is Signed:\t" << read.getSigned() << std::endl;
	out << "Grade toSign:\t" << read.getGradeSign() << std::endl;
	out << "Grade toExec:\t" << read.getGradeExec() << std::endl;
	return (out);
}


