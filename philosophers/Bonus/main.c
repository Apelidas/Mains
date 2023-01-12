/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:59:32 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 11:23:46 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cont_philo(t_all *data)
{
	pthread_t	thread;
	int			i;

	if (data->in->number > 0)
	{
		if (pthread_create(&thread, NULL, &thread_rout, data) != 0)
		{
			err("THREAD_CREATION_ERROR");
			return ;
		}
	}
	sem_wait(data->death);
	kill_all(data);
	i = 0;
	while (i < data->in->number)
	{
		sem_post(data->eaten);
		i++;
	}
	pthread_join(thread, NULL);
}

static int	start_helper(t_all *data, t_philo *phil, int i, long int time)
{
	int	check;

	phil->start->time = time;
	phil->lmeal->time = time;
	check = fork();
	if (check == -1)
	{
		err("FORK_FAILED");
		kill_all(data);
		return (1);
	}
	if (check == 0)
		routine(phil);
	data->pid[i] = check;
	return (0);
}

void	start_philo(t_all *data)
{
	int			i;
	long int	time;
	t_philo		*phil;

	i = 0;
	time = get_time();
	phil = data->lst;
	while (phil)
	{
		if (start_helper(data, phil, i, time))
			return ;
		i++;
		phil = phil->next;
	}
	cont_philo(data);
}

int	main(int argc, char **argv)
{
	t_all	*data;
	t_input	*in;

	if (input_check(argc, argv, &in) < 1)
	{
		free(in);
		return (0);
	}
	data = create_all(in);
	if (!data)
	{
		free(in);
		return (0);
	}
	if (check_zero(data))
		start_philo(data);
	destroy_all(data);
	return (0);
}
