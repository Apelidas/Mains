#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Passierschein A38"), grade(150)
{
}

Bureaucrat::Bureaucrat(int grade): name("Passierschein A38")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw  Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy): name(copy.name), grade(copy.grade)
{
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &read)
{
	out << read.getName() << ", bureaucrat grade " << read.getGrade() << std::endl;
	return (out);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade is too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade is too low!");
}
