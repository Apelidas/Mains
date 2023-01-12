/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:24:17 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 13:40:49 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *phil)
{
	int	check;

	if (check_starve(phil))
		return (1);
	pthread_mutex_lock(&phil->death->mut);
	check = phil->death->bol;
	pthread_mutex_unlock(&phil->death->mut);
	if (check == 1)
		return (1);
	return (0);
}

int	check_starve(t_philo *phil)
{
	if (get_time() - phil->lmeal <= phil->die)
		return (0);
	philo_death(phil);
	return (1);
}

static void	check_fork(t_fork *fork, int *check, t_philo *phil)
{
	pthread_mutex_lock(&fork->mut);
	if (fork->bol == 0)
	{
		fork->bol = 1;
		*check = 2;
		write_ms(get_time(), phil, "has taken a fork");
	}
	pthread_mutex_unlock(&fork->mut);
}

int	block_forks(t_philo *phil)
{
	int	lcheck;
	int	rcheck;

	lcheck = 1;
	rcheck = 1;
	while (lcheck != 2 || rcheck != 2)
	{
		check_fork(phil->lfork, &lcheck, phil);
		check_fork(phil->rfork, &rcheck, phil);
		if (check_death(phil))
			return (-1);
	}
	return (1);
}

void	unblock_forks(t_philo *phil)
{
	pthread_mutex_lock(&phil->lfork->mut);
	phil->lfork->bol = 0;
	pthread_mutex_unlock(&phil->lfork->mut);
	pthread_mutex_lock(&phil->rfork->mut);
	phil->rfork->bol = 0;
	pthread_mutex_unlock(&phil->rfork->mut);
}
