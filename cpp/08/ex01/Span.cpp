#include "Span.hpp"

Span::Span(): _n(0)
{}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	this->_values.clear();
	this->_n = copy._n;
	this->_values.insert(this->_values.begin(), copy._values.begin(), copy._values.end());
	return (*this);
}

Span::Span(unsigned int n): _n(n)
{
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

void Span::addMany(int in)
{
	this->_values.insert(this->_values.begin(), in, 0);
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