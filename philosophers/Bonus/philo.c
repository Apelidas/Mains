/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:54:23 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 13:17:23 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_help(t_philo *out, t_all *data, int pid)
{
	out->nmeals = data->in->number;
	out->die = data->in->die;
	out->eat = data->in->eat;
	out->amount = data->in->amount;
	out->sleep = data->in->sleep;
	out->eaten = data->eaten;
	out->pid = pid;
	out->forks = data->forks;
	out->death = data->death;
	out->print = data->print;
	out->next = NULL;
}

t_philo	*create_philo(t_all *data, int pid)
{
	t_philo	*out;

	out = malloc(sizeof(t_philo));
	if (!out)
		return (err("MALLOC_ERROR create"));
	out->lmeal = malloc(sizeof(t_death));
	if (!out->lmeal)
		return (err_id(3, "MALLOC_ERROR lmeal", out));
	if (pthread_mutex_init(&out->lmeal->mut, NULL) != 0)
	{
		free(out->lmeal);
		out->lmeal = NULL;
		return (err("MUTEX_ERROR lmeal"));
	}
	out->start = malloc(sizeof(t_death));
	if (!out->start)
		return (err("MALLOC_ERROR lmeal"));
	if (pthread_mutex_init(&out->start->mut, NULL) != 0)
	{
		free(out->start);
		out->start = NULL;
		return (err("MUTEX_ERROR start"));
	}
	create_help(out, data, pid);
	return (out);
}

void	*create_lst(t_all *data)
{
	t_philo	*help;
	t_philo	*tmp;
	int		i;

	i = 1;
	data->lst = create_philo(data, 0);
	if (!data->lst)
		return (err("LST_ERROR start"));
	tmp = data->lst;
	while (i < data->in->amount)
	{
		help = create_philo(data, i);
		if (!help)
			return (err_id(1, "LST_ERROR loop", data->lst));
		tmp->next = help;
		tmp = help;
		i++;
	}
	return ("1");
}

static void	destroy_help(t_philo *start)
{
	if (start->lmeal)
	{
		pthread_mutex_destroy(&start->lmeal->mut);
		free(start->lmeal);
	}
	if (start->start)
	{
		pthread_mutex_destroy(&start->start->mut);
		free(start->start);
	}
	free(start);
}

void	destroy_lst(t_philo *start)
{
	t_philo	*help;

	if (!start)
		return ;
	while (start->next)
	{
		help = start;
		start = start->next;
		if (help->lmeal)
		{
			pthread_mutex_destroy(&help->lmeal->mut);
			free(help->lmeal);
		}
		if (help->start)
		{
			pthread_mutex_destroy(&help->start->mut);
			free(help->start);
		}
		free(help);
	}
	destroy_help(start);
}
