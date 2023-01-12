/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:01:58 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 11:33:24 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_help(t_philo *out, t_all *data)
{
	out->rfork = NULL;
	out->death = NULL;
	out->next = NULL;
	out->lmeal = -1;
	out->pid = -1;
	out->nmeals = data->in->number;
	out->amount = data->in->amount;
	out->die = data->in->die;
	out->eat = data->in->eat;
	out->sleep = data->in->sleep;
	out->nmeals = data->in->number;
	out->death = data->death;
	out->print = &data->print;
	out->eaten = data->eaten;
	out->start = 0;
}

t_philo	*create_t_philo(t_all *data)
{
	t_philo	*out;

	out = malloc(sizeof(t_philo));
	if (!out)
		return (err_id(0, "MALLOC_ERROR philo", NULL));
	out->pid = -1;
	out->lfork = malloc(sizeof(t_fork));
	if (!out->lfork)
		return (err_id(1, "MALLOC_ERROR lfork", out));
	out->lfork->bol = 0;
	if (pthread_mutex_init(&(out->lfork->mut), NULL) != 0)
		return (err_id(1, "MUTEX_INIT_ERROR", out));
	philo_help(out, data);
	return (out);
}

void	destroy_philo(t_philo *todel)
{
	if (!todel)
		return ;
	if (todel->lfork)
	{
		pthread_mutex_destroy(&todel->lfork->mut);
		free(todel->lfork);
	}
	free(todel);
}

t_philo	*philo_list(t_all *data)
{
	t_philo	*help;
	t_philo	*start;
	t_philo	*tmp;
	int		i;

	i = 1;
	start = create_t_philo(data);
	if (!start)
		return (NULL);
	help = start;
	start->pid = 0;
	while (i < data->in->amount)
	{
		tmp = create_t_philo(data);
		if (!tmp)
			return (destroy_philo_list(start));
		tmp->pid = i;
		help->next = tmp;
		help->rfork = tmp->lfork;
		help = help->next;
		i++;
	}
	help->next = start;
	help->rfork = start->lfork;
	return (start);
}

void	*destroy_philo_list(t_philo *start)
{
	t_philo	*help;
	t_philo	*todel;

	if (!start)
		return (NULL);
	if (start->next == start)
	{
		destroy_philo(start);
		return (NULL);
	}
	help = start->next;
	while (help->next && help->next != start)
	{
		todel = help;
		help = help->next;
		destroy_philo(todel);
	}
	destroy_philo(help);
	destroy_philo(start);
	return (NULL);
}
