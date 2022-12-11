#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade): name("Passierschein A38")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw  Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw  Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor" << std::endl;
}

std::string const Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increment()
{
	if(this->grade == 1)
		throw  Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrement()
{
	if(this->grade == 150)
		throw  Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::beSigned(AForm &tosign)
{
	if (this->getGrade() > tosign.getGradeSign())
	{
		std::cout << this->getName() << " couldn't sign " << tosign.getName() << " because of his Grade being too low" << std::endl;
	}
	else
	{
		tosign.beSigned(*this);
		std::cout << this->getName() << " signed " << tosign.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(AForm::FormNotSignedException)
	{
		std::cerr << this->name << " forgot to sign " << form.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException)
	{
		std::cerr << this->name << " is not High enough in Rank to execute " << form.getName() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &read)
{
	out << read.getName() << ", bureaucrat grade " << read.getGrade() << std::endl;
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade is too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade is too low!");
}
