/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:15:02 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/19 12:19:11 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact array[8];
};


void add(PhoneBook *book, int i);
void search(PhoneBook book, int len);

#endif