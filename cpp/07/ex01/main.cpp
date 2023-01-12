#include "iter.hpp"



int main()
{
	int array[] = { 4, 3, 2, 1, 0};
	std::string arrayst[] = {"hello ", "this", " is a ", "string-array"};

	std::cout << "Test int Array" << std::endl;
	iter<int>(array, 5, &printer<int>);

	std::cout << "Test string Array" << std::endl;
	iter<std::string>(arrayst, 4, &printer<std::string>);
}