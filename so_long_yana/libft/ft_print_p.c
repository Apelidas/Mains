/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:05:30 by ydimitro          #+#    #+#             */
/*   Updated: 2022/05/24 12:05:30 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	createaddrstr(unsigned long int n, int counter)
{
	int	last_digit;

	if (counter == 0)
		counter += write(1, "0x", 2);
	if (n >= 16)
		counter = createaddrstr(n / 16, counter);
	last_digit = n % 16;
	counter += write(1, &"0123456789abcdef"[last_digit], 1);
	return (counter);
}

int	ft_print_p(va_list *args)
{
	unsigned long int	n;
	int					counter;

	n = va_arg(*args, unsigned long int);
	counter = createaddrstr(n, counter = 0);
	return (counter);
}
