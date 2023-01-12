#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeSign;
		int const _gradeExec;

	public:
		Form();
		Form(Form &copy);
		Form& operator=(Form &copy);
		Form(int gradeSign, int gradeExec, std::string name);
		~Form();
		std::string const getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat const &toSign);

		class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, Form const &read);

#endif