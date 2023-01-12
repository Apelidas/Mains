#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *ptr = &brain;
	std::string &ref = brain;

	

	std::cout << "The Pointer Ori:" << &brain << "\n";
	std::cout << "The Pointer VAR:" << ptr << "\n";
	std::cout << "The Pointer REF:" << &ref << "\n";

	std::cout << "The String ORI:" << brain << "\n";
	std::cout << "The String VAR:" << *ptr << "\n";
	std::cout << "The String REF:" << ref << "\n";
}