#include "Span.hpp"

Span::Span(unsigned int n)
{
	this->_n = n;
}

void Span::addNumber()
{
	if (this->_values.size() == this->_n)
		throw Span::Full();
	static int toAdd = 0;
	this->_values.push_back(toAdd++);
}

void Span::addNumber(int in)
{
	if (this->_values.size() == this->_n)
		throw Span::Full();
	this->_values.push_back(in);
}

unsigned int Span::shortestSpan()
{
	unsigned int out;

	if (this->_values.empty() || this->_values.size() < 2)
		throw Span::Nope();
	std::sort(this->_values.begin(), this->_values.end());
	out = this->_values.front();
	out = this->_values[1] - out;
	return (out);
}

unsigned int Span::longestSpan()
{
	unsigned int out;

	if (this->_values.empty() || this->_values.size() < 2)
		throw Span::Nope();
	std::sort(this->_values.begin(), this->_values.end());
	out = this->_values.front();
	out = this->_values.back();
	return (out);
}