#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
	std::string const name;
	int grade;

	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &copy);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		std::string const getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void beSigned(AForm &tosign);
		void executeForm(AForm const &form);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	}; 

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &read);

#endif