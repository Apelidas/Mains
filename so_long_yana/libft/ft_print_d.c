/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:05:47 by ydimitro          #+#    #+#             */
/*   Updated: 2022/05/24 12:05:47 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_d(va_list *args)
{
	int		d;
	char	*str;

	d = va_arg(*args, int);
	str = ft_itoa(d);
	ft_putstr_fd(str, 1);
	d = ft_strlen(str);
	free(str);
	return (d);
}
