/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:24:01 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 13:15:01 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_thread(void *in)
{
	long int	time;
	t_philo		*phil;

	phil = (t_philo *) in;
	while (1)
	{
		usleep(800);
		pthread_mutex_lock(&phil->lmeal->mut);
		time = phil->lmeal->time;
		pthread_mutex_unlock(&phil->lmeal->mut);
		if (get_time() - time > phil->die)
			break ;
	}
	sem_post(phil->death);
	write_death(get_time(), phil, "has died");
	return (NULL);
}

static void	sleeping(long int time, long int dur)
{
	while (get_time() - time < dur)
		usleep(100);
}

void	eat(t_philo *phil)
{
	long int	help;

	sem_wait(phil->forks);
	write_ms(get_time(), phil, "has taken a fork");
	sem_wait(phil->forks);
	write_ms(get_time(), phil, "has taken a fork");
	pthread_mutex_lock(&phil->lmeal->mut);
	phil->lmeal->time = get_time();
	help = phil->lmeal->time;
	pthread_mutex_unlock(&phil->lmeal->mut);
	write_ms(help, phil, "is eating");
	sleeping(help, phil->eat);
	if (phil->nmeals != -1)
		phil->nmeals--;
	if (phil->nmeals == 0)
		sem_post(phil->eaten);
	sem_post(phil->forks);
	sem_post(phil->forks);
}

void	routine(t_philo *phil)
{
	pthread_t	t;

	if (pthread_create(&t, NULL, &death_thread, phil) != 0)
	{
		err("THREAD_CREATION_ERROR");
		sem_post(phil->death);
		return ;
	}
	if (phil->pid % 2 == 1)
	{
		write_ms(get_time(), phil, "is thinking");
		usleep(1000);
	}
	while (1)
	{
		eat(phil);
		write_ms(get_time(), phil, "is sleeping");
		sleeping(get_time(), phil->sleep);
		write_ms(get_time(), phil, "is thinking");
	}
}
