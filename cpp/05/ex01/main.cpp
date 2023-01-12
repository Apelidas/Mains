#include "Bureaucrat.hpp"

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

void testForm()
{
	Form a;
	std::cout << a << std::endl;

	Form b( 42, 21,"28B");
	std::cout << b << std::endl;

	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Positive(No Exception)                                   |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	{
		try
		{
			Bureaucrat c("Asterix", 21);
			c.beSigned(b);
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Negative(TooLow)                                         |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	{
		try
		{
			Bureaucrat c("Asterix", 43);
			c.beSigned(b);
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Negative(ExceptionLow)                                   |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;

	{
		try
		{
			Bureaucrat c("Asterix", 43);
			b.beSigned(c);
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}


}

int main(void)
{
	testBur();
	std::cout << std::endl;
	testForm();
	std::cout << std::endl;
}