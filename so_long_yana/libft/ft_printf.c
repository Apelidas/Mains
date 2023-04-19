/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:11:28 by ydimitro          #+#    #+#             */
/*   Updated: 2022/05/24 09:11:28 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_cases(char c, va_list *args, int counter);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*ptf;
	int		counter;
	int		index;

	ptf = (char *) format;
	counter = 0;
	index = 0;
	va_start(args, format);
	while (ptf[index])
	{
		if (ptf[index] != '%')
		{
			ft_putchar_fd(ptf[index], 1);
			index++;
			counter++;
		}
		else
		{
			counter = check_cases(ptf[index + 1], &args, counter);
			index += 2;
		}
	}
	va_end(args);
	return (counter);
}

int	check_cases(char c, va_list *args, int counter)
{
	if (c == 'c')
		counter += ft_print_c(args);
	else if (c == 's')
		counter += ft_print_s(args);
	else if (c == '%')
		counter += ft_print_percent();
	else if (c == 'd' || c == 'i')
		counter += ft_print_d(args);
	else if (c == 'u')
		counter += ft_print_u(args);
	else if (c == 'p')
		counter += ft_print_p(args);
	else if (c == 'x')
		counter += ft_print_x(args);
	else if (c == 'X')
		counter += ft_print_xup(args);
	return (counter);
}
