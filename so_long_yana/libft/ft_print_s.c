/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:07:47 by ydimitro          #+#    #+#             */
/*   Updated: 2022/05/24 12:07:47 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_s(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
