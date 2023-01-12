/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:32:24 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/21 14:17:54 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string Contact::get_first()
{
	return (this->first);
}

std::string Contact::get_last()
{
	return (this->last);
}

std::string Contact::get_nick()
{
	return (this->nick);
}

std::string Contact::get_number()
{
	return (this->number);
}

std::string Contact::get_secret()
{
	return (this->secret);
}

void Contact::set_first(std::string in)
{
	this->first = in;
}

void Contact::set_last(std::string in)
{
	this->last = in;
}

void Contact::set_nick(std::string in)
{
	this->nick = in;
}

void Contact::set_number(std::string in)
{
	this->number = in;
}

void Contact::set_secret(std::string in)
{
	this->secret = in;
}

void read(PhoneBook book)
{
	std::string in;
	int			i;

	i = 0;
	std::cout << "Type a Command:\n";
	while (std::getline(std::cin, in))
	{
		if (in == "ADD")
		{
			add(&book, i % 8);
			i++;
		}
		else if (in == "SEARCH")
		{
			if (i > 8)
				search(book, 8);
			else
				search(book, i);
		}
		else if (in == "EXIT")
			break;
		std::cout << "Type a Command:\n";
	}
}

int main()
{
	PhoneBook	book;

	read(book);
}