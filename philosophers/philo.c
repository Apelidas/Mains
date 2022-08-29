/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:01:58 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/29 13:26:54 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_t_philo(void)
{
	t_philo	*out;

	out = malloc(sizeof(t_philo));
	if (!out)
		return (err("MALLOC_ERROR t_philo"));
	out->pid = -1;
	out->lfork = malloc(sizeof(t_fork));
	if (!out->lfork)
		return (philo_err(out, "FORK_CREATION_ERROR"));
	out->lfork->bol = 1;
	if (pthread_mutex_init(&(out->lfork->mut), NULL) != 0)
		return (philo_err(out, "MUTEX_INIT_ERROR"));
	out->rfork = NULL;
	out->death = NULL;
	out->next = NULL;
	out->lmeal = -1;
	out->pid = -1;
	out->nmeals = 0;
	return (out);
}

void	destroy_philo(t_philo *todel)
{
	if (!todel)
		return ;
	if (todel->lmeal)
		free(&todel->lmeal);
	if (todel->lfork)
	{
		pthread_mutex_destroy(&todel->lfork->mut);
		free(todel->lfork);
	}
	free(todel);
}

t_philo	*philo_list(int amount)
{
	t_philo	*help;
	t_philo	*start;
	t_philo	*tmp;
	int		i;

	i = 1;
	start = create_t_philo();
	if (!start)
		return (0);
	help = start;
	while (i < amount)
	{
		tmp = create_t_philo();
		if (!tmp)
			return (destroy_philo_list(start));
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
