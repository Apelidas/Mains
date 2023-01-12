/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:59:32 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 11:59:37 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*create_stuff(t_all *all, pthread_t **th, t_philo **tmp, long int *t)
{
	struct timeval	time;

	*th = malloc(sizeof(pthread_t) * (all->in->amount));
	if (!th)
		return (err_id(0, "MALLOC_ERROR threads", NULL));
	all->lst = philo_list(all);
	if (!all->lst)
		return (err_id(3, "LIST_ERROR start", th));
	*tmp = all->lst;
	if (gettimeofday(&time, NULL) != 0)
		return (err_id(3, "TIME_ERROR start", th));
	*t = get_ms(&time);
	if (*t == 0)
	{
		free(*th);
		return (NULL);
	}
	return ("1");
}

int	help(t_all *all, pthread_t *threads, long int t, t_philo *tmp)
{
	int	i;

	i = 0;
	while (i < all->in->amount)
	{
		tmp->start = t;
		tmp->lmeal = t;
		if (pthread_create(&threads[i], NULL, &routine, tmp) != 0)
		{
			pthread_mutex_lock(&all->death->mut);
			all->death->bol = 1;
			pthread_mutex_unlock(&all->death->mut);
			err("THREAD_CREATION_ERROR");
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	*init_thread(t_all *all)
{
	t_philo			*tmp;
	int				i;
	pthread_t		*threads;
	long int		t;

	i = 0;
	if (!create_stuff(all, &threads, &tmp, &t))
		return (NULL);
	i = help(all, threads, t, tmp);
	while (i >= 0)
	{
		pthread_join(threads[i], NULL);
		i--;
	}
	free(threads);
	return (NULL);
}

int	check_zero(t_all *data)
{
	if (data->in->amount <= 0)
		return (err_int("Food went cold. Nobody showed up"));
	if (data->in->die <= 0)
		return (err_int("They are dead"));
	if (data->in->sleep <= 0)
		return (err_int("No time to sleep"));
	if (data->in->eat <= 0)
		return (err_int("You won the eating contest"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_all	*data;

	data = create_all();
	if (input_check(argc, argv, data->in) < 1)
	{
		destroy_all(data);
		return (0);
	}
	if (check_zero(data))
		init_thread(data);
	destroy_all(data);
	return (0);
}
