/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:04:08 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/01/10 13:09:31 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (num);
}

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				help;

	help = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		help = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	num = ft_getnum(str) * help;
	return (num);
}
