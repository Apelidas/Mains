#include "Array.hpp"

void testint()
{
	Array<int> a(20);
	Array<int> b(9);
	

	std::cout << "Test<int>" << std::endl;
	for (int i = 0; i < a.size(); i++)
	{
		a[i] = i + 1;
		std::cout << "a[" << i << "]:" << a[i] << std::endl; 
	}
	std::cout << std::endl;
	for (int i = 0; i < b.size(); i++)
	{
		b[i] = b.size() - i;
		std::cout << "b[" << i << "]:" << b[i] << std::endl; 
	}
	std::cout << "Call copy operator" << std::endl;
	b = a;
	std::cout << "_________________";
	std::cout << "a:" << std::endl;
	a.print();
	std::cout << "_________________";
	std::cout << "b:" << std::endl;
	a.print();
}

void teststring()
{
	Array<std::string> a(9);
	Array<std::string> b(9);
	std::string help[] = {"this", "is", "a", "little", "string-array", "for", "testing", "purposes", "."};
	std::cout << "Test<string>" << std::endl;
	for (int i = 0; i < a.size(); i++)
	{
		a[i] = help[8 - i];
		std::cout << "a[" << i << "]:" << a[i] << std::endl; 
	}
	std::cout << std::endl;
	for (int i = 0; i < b.size(); i++)
	{
		b[i] = help[i];
		std::cout << "b[" << i << "]:" << b[i] << std::endl; 
	}

	std::cout << "Call copy operator" << std::endl;
	b = a;
	std::cout << "_________________";
	std::cout << "a:" << std::endl;
	a.print();
	std::cout << "_________________";
	std::cout << "b:" << std::endl;
	a.print();
}

int main()
{
	testint();
	std::cout << "_______________________";
	teststring();
}