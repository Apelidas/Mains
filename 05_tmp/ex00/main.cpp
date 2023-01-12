#include "Bureaucrat.hpp"

void test()
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

int main(void)
{
	test();
	std::cout << std::endl;
}