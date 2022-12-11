#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
	std::string const name;
	int grade;

	public:
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		std::string const getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void beSigned(Form &tosign);

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