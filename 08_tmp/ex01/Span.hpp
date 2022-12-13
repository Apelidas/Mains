#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int> _values;
		unsigned int _n;

	public:
		Span(unsigned int n);
		~Span(){}
		void addNumber();
		void addNumber(int in);
		unsigned int shortestSpan();
		unsigned int longestSpan();

	class Nope: public std::exception
	{
		const char *what() const throw() {return ("Not enough values in the list");}
	};

	class Full: public std::exception
	{
		const char *what() const throw() {return ("The list is already full");}
	};


};

#endif