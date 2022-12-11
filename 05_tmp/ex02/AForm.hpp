#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeSign;
		int const _gradeExec;

	public:
		AForm();
		AForm(int gradeSign, int gradeExec, std::string name);
		virtual ~AForm();
		virtual std::string const getName() const;
		virtual bool getSigned() const;
		virtual int getGradeSign() const;
		virtual int getGradeExec() const;
		virtual void beSigned(Bureaucrat const &toSign);
		virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, AForm const &read);

#endif