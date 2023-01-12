#include "PhoneBook.hpp"

std::string info(std::string in)
{
	std::string out;

	if (in.length() > 9)
	{
		out = in.substr(0, 8);
		out += '.';
	}
	else
		out = in;
	return (out);
}

void print_contact(Contact in, int index)
{
	std::cout << std::setw(10) << index << '|';
	std::cout << std::setw(10) << info(in.get_first()) << '|';
	std::cout << std::setw(10) << info(in.get_last()) << '|';
	std::cout << std::setw(10) << info(in.get_nick()) << '|';
	std::cout << std::setw(10) << info(in.get_number()) << "\n";
}

bool is_num(std::string in)
{
	int i;

	i = 0;
	while (in[i])
	{
		if (in[i] < '0' || in[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int ft_atoi(std::string in)
{
	int i;
	int out;

	i = 0;
	out = 0;
	while (in[i])
	{
		out = out * 10;
		out += in[i] - '0';
		i++;
	}
	return (out);
}

void search(PhoneBook book, int len)
{
	int	i;

	std::string red;

	i = 0;
	while (i < len)
	{
		print_contact(book.array[i], i);
		i++;
	}
	if (len == 0)
	{
		std::cout << "Phonebook is currently empty\n";
		return ;
	}
	std::cout << "Choose an index:\n";
	while (1)
	{
		std::getline(std::cin, red);
		if (!is_num(red))
			std::cerr << "Please type in a number in Range\n";
		else
		{
			i = ft_atoi(red);
			if ( i < len)
				break ;
			else
				std::cerr << "Please type in a number in Range\n";
		}
	}
	std::cout << book.array[i].get_first() << "\n";
	std::cout << book.array[i].get_last() << "\n";
	std::cout << book.array[i].get_nick() << "\n";
	std::cout << book.array[i].get_number() << "\n";
	std::cout << book.array[i].get_secret() << "\n";
}