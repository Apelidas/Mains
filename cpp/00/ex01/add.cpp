#include "PhoneBook.hpp"

void add(PhoneBook *book, int i)
{
	std::string red;

	std::cout << "first Name:\n";
	while (1)
	{
		if (std::getline(std::cin, red) == 0)
			exit(1);
		if (red == "")
		{
			std::cerr << "Value cannot be empty\n";
			return ;
		}
		else
			break;
	}
	book->array[i].set_first(red);
	
	std::cout << "last Name:\n";
	while (1)
	{
		if (std::getline(std::cin, red) == 0)
			exit(1);
		if (red == "")
		{
			std::cerr << "Value cannot be empty\n";
			return ;
		}
		else
			break;
	}
	book->array[i].set_last(red);
	
	std::cout << "Nickname:\n";
	while (1)
	{
		if (std::getline(std::cin, red) == 0)
			exit(1);
		if (red == "")
		{
			std::cerr << "Value cannot be empty\n";
			return ;
		}
		else
			break;
	}
	book->array[i].set_nick(red);
	
	std::cout << "Number:\n";
	while (1)
	{
		if (std::getline(std::cin, red) == 0)
			exit(1);
		if (red == "")
		{
			std::cerr << "Value cannot be empty\n";
			return ;
		}
		else
			break;
	}
	book->array[i].set_number(red);
	
	std::cout << "Darkest Secret:\n";
	while (1)
	{
		if (std::getline(std::cin, red) == 0)
			exit(1);
		if (red == "")
		{
			std::cerr << "Value cannot be empty\n";
		}
		else
			break;
	}
	book->array[i].set_secret(red);
}