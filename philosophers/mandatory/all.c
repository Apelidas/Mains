/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:56:30 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 11:33:45 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*help_create(t_all *out)
{
	if (pthread_mutex_init(&out->print, NULL) != 0)
		return (err_id(2, "MUTEX_INIT_ERROR death", out));
	out->death = malloc(sizeof(t_fork));
	if (!out->death)
		return (err_id(5, "MALLOC_ERROR death", NULL));
	if (pthread_mutex_init(&out->death->mut, NULL) != 0)
		return (err_id(5, "MUTEX_INIT_ERROR death", out));
	out->death->bol = 0;
	out->eaten = malloc(sizeof(t_fork));
	if (!out->eaten)
		return (err_id(5, "MALLOC_ERROR death", NULL));
	if (pthread_mutex_init(&out->eaten->mut, NULL) != 0)
		return (err_id(5, "MUTEX_INIT_ERROR death", out));
	out->eaten->bol = 0;
	return ("1");
}

t_all	*create_all(void)
{
	t_all	*out;

	out = malloc(sizeof(t_all));
	if (!out)
		return (err_id(0, "MALLOC_ERROR all", NULL));
	out->lst = NULL;
	out->in = create_input();
	if (!out->in)
	{
		free(out);
		return (err_id(0, "MALLOC_ERROR in", NULL));
	}
	if (!help_create(out))
		return (NULL);
	return (out);
}

void	destroy_all(t_all *todel)
{
	if (!todel)
		return ;
	if (todel->lst)
		destroy_philo_list(todel->lst);
	if (todel->in)
		free(todel->in);
	if (todel->death)
	{
		pthread_mutex_destroy(&todel->death->mut);
		free(todel->death);
	}
	if (todel->eaten)
	{
		pthread_mutex_destroy(&todel->eaten->mut);
		free(todel->eaten);
	}
	pthread_mutex_destroy(&todel->print);
	free(todel);
}
