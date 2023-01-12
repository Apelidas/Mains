/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:06:40 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 13:36:48 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_death(t_philo *phil)
{
	int	check;

	check = 0;
	pthread_mutex_lock(&phil->death->mut);
	check = phil->death->bol;
	if (check == 0)
		phil->death->bol = 1;
	pthread_mutex_unlock(&phil->death->mut);
	if (check == 0)
		write_death(get_time(), phil, "has died");
	return (NULL);
}

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
	if (num > 2147483647)
		return (-1);
	return (num);
}

void	write_ms(long int time, t_philo *philo, char *out)
{
	int	check;

	pthread_mutex_lock(philo->print);
	pthread_mutex_lock(&philo->death->mut);
	check = philo->death->bol;
	pthread_mutex_unlock(&philo->death->mut);
	if (check == 0)
		printf("%ld %d %s\n", time - philo->start, philo->pid, out);
	pthread_mutex_unlock(philo->print);
}

void	write_death(long int time, t_philo *philo, char *out)
{
	pthread_mutex_unlock(&philo->death->mut);
	printf("%ld %d %s\n", time - philo->start, philo->pid, out);
	pthread_mutex_unlock(philo->print);
}
