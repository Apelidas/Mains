/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:10:46 by ydimitro          #+#    #+#             */
/*   Updated: 2022/05/24 12:10:46 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_x(va_list *args)
{
	unsigned int	nbr;
	int				counter;

	nbr = va_arg(*args, unsigned int);
	counter = ft_print_hex(nbr, 'x');
	return (counter);
}
