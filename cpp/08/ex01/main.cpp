#include "Span.hpp"

void testadd()
{
	Span myvec(2);

	std::cout << "\nTest with vector(2) and 1 Element" << std::endl;
	myvec.addNumber();
	std::cout << "shortestSpan:";
	try
	{
		myvec.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "longestSpan:";
	try
	{
		myvec.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nTest with vector(2) and 2 Element" << std::endl;
	myvec.addNumber();
	std::cout << "shortestSpan:";
	try
	{
		std::cout << myvec.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "longestSpan:";
	try
	{
		std::cout << myvec.longestSpan() << std::endl;;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTest with vector(2) add 3rd element" << std::endl;

	try
	{
		myvec.addNumber();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testgiven()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void testlots()
{
	Span myvec(20000);

	myvec.addMany(20000);

	std::cout << "shortestSpan:";
	try
	{
		std::cout << myvec.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "longestSpan:";
	try
	{
		std::cout << myvec.longestSpan() << std::endl;;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	testadd();
	std::cout << "_________________________" << std::endl;
	testgiven();
	std::cout << "_________________________" << std::endl;
	testlots();
}