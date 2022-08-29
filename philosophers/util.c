/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:06:40 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/27 15:58:24 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_getnum(const char *str)
{
	int	num;

	num = 0;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10;
		num = num + *str - 48;
		str++;
	}
	if (!*str)
		return (num);
	return (-1);
}

int	ft_atoi(const char *str)
{
	long int	num;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
	{
		str++;
	}
	num = ft_getnum(str);
	if (num == -1)
		return (-1);
	return (num);
}
