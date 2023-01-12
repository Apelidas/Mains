/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:08:32 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 11:56:38 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	time_skip(t_philo *phil, long int time, long int dur)
{
	while (get_time() - time < dur)
	{
		usleep(50);
		if (check_death(phil))
			return (0);
	}
	return (1);
}

static int	check_nmeal(t_philo *phil)
{
	int	check;

	if (phil->nmeals != 0)
		return (1);
	pthread_mutex_lock(&phil->eaten->mut);
	check = phil->eaten->bol;
	pthread_mutex_unlock(&phil->eaten->mut);
	if (check == phil->amount)
	{
		pthread_mutex_lock(&phil->death->mut);
		phil->death->bol = 1;
		pthread_mutex_unlock(&phil->death->mut);
		return (0);
	}
	return (1);
}

int	eat(t_philo *phil)
{
	long int	time;

	if (check_death(phil))
		return (0);
	if (block_forks(phil) == -1)
		return (0);
	time = get_time();
	if (time == 0)
		return (0);
	write_ms(time, phil, "is eating");
	phil->lmeal = time;
	if (!time_skip(phil, time, phil->eat))
		return (0);
	if (phil->nmeals >= 0)
		phil->nmeals--;
	return (1);
}

static int	loop_routine( t_philo *phil)
{
	if (!eat(phil))
	{
		unblock_forks(phil);
		return (0);
	}
	if (phil->nmeals == 0)
	{
		pthread_mutex_lock(&phil->eaten->mut);
		phil->eaten->bol++;
		pthread_mutex_unlock(&phil->eaten->mut);
	}
	if (!check_nmeal(phil))
		return (0);
	write_ms(get_time(), phil, "is sleeping");
	unblock_forks(phil);
	if (check_death(phil))
		return (0);
	if (!time_skip(phil, get_time(), phil->sleep))
		return (0);
	if (!check_nmeal(phil))
		return (0);
	write_ms(get_time(), phil, "is thinking");
	return (1);
}

void	*routine(void *in)
{
	t_philo		*phil;

	phil = (t_philo *) in;
	if (phil->pid % 2 == 1)
	{
		usleep(5000);
		write_ms(get_time(), phil, "is thinking");
	}
	while (check_nmeal(phil))
	{
		if (!loop_routine(phil))
			return (NULL);
	}
	return (NULL);
}
