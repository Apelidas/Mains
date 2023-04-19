/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:08:21 by ydimitro          #+#    #+#             */
/*   Updated: 2022/05/24 12:08:21 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(va_list *args)
{
	unsigned int	d;
	char			*str;

	d = va_arg(*args, unsigned int);
	str = ft_print_uns_itoa(d);
	ft_putstr_fd(str, 1);
	d = ft_strlen(str);
	free(str);
	return (d);
}
