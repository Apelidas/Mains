#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testBur()
{
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Positive(No Output)                                      |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	{
		try
		{
			Bureaucrat ast("Asterix", 42);
		}
		catch(Bureaucrat::GradeTooHighException &a)
		{
			std::cout << a.what();
		}
		catch(Bureaucrat::GradeTooLowException &a)
		{
			std::cout << a.what();
		}
	}
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Negative(TooLow)                                         |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	{
		try
		{
			Bureaucrat ast("Asterix", 151);
		}
		catch(Bureaucrat::GradeTooHighException &a)
		{
			std::cout << a.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &a)
		{
			std::cout << a.what() << std::endl;
		}
	}

	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Negative(TooHigh)                                        |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	{
		try
		{
			Bureaucrat ast("Asterix", 0);
		}
		catch(Bureaucrat::GradeTooHighException &a)
		{
			std::cout << a.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &a)
		{
			std::cout << a.what() << std::endl;
		}
	}
}

void TestFormExec()
{
	PresidentialPardonForm a("Asterix");
	ShrubberyCreationForm b("niceTree");
	RobotomyRequestForm c("Bender");
	Bureaucrat d("Caesar", 1);
	Bureaucrat e("Verleihnix", 45);
	Bureaucrat f("Automatix", 150);
	

	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Positive(No Output)                                      |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	d.beSigned(a);
	d.beSigned(b);
	d.beSigned(c);
	d.executeForm(a);
	d.executeForm(b);
	d.executeForm(c);

	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Mix                                                      |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	e.executeForm(a);
	e.executeForm(b);
	e.executeForm(c);

	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Negative                                                 |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	f.executeForm(a);
	f.executeForm(b);
	f.executeForm(c);

}


int main(void)
{
	testBur();
	std::cout << std::endl;
	TestFormExec();
	std::cout << std::endl;
}