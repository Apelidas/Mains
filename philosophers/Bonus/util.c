/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:30:35 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 13:15:36 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_ms(long int time, t_philo *philo, char *out)
{
	sem_wait(philo->print);
	printf("%ld %d %s\n", time - philo->start->time, philo->pid, out);
	sem_post(philo->print);
}

void	write_death(long int time, t_philo *philo, char *out)
{
	sem_wait(philo->print);
	printf("%ld %d %s\n", time - philo->start->time, philo->pid, out);
	sem_wait(philo->print);
}

void	kill_all(t_all *data)
{
	int	i;

	i = 0;
	while (data->pid[i] != -1 && i < data->in->amount)
	{
		kill(data->pid[i], SIGKILL);
		i++;
	}
}

void	*thread_rout(void *in)
{
	t_all	*data;
	int		i;

	data = (t_all *) in;
	i = 0;
	while (i < data->in->amount)
	{
		sem_wait(data->eaten);
		i++;
	}
	sem_post(data->death);
	return (NULL);
}
