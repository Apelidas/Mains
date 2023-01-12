/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:24:01 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 11:16:43 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*init_sem(t_all *out, t_input *in)
{
	sem_unlink("/death");
	out->death = sem_open("/death", O_CREAT | O_EXCL, 0644, 0);
	if (out->death == SEM_FAILED)
		return (err_id(3, "SEM_ERROR death", out));
	if (in->number >= 0)
	{
		sem_unlink("/eaten");
		out->eaten = sem_open("/eaten", O_CREAT | O_EXCL, 0644, 0);
		if (out->eaten == SEM_FAILED)
			return (err_id(0, "SEM_ERROR eaten", out));
	}
	sem_unlink("/print");
	out->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	if (out->eaten == SEM_FAILED)
		return (err_id(0, "SEM_ERROR print", out));
	sem_unlink("/forks");
	out->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, in->amount);
	if (out->forks == SEM_FAILED)
		return (err_id(0, "SEM_ERROR forks", out));
	return ("1");
}

t_all	*create_all(t_input *in)
{
	t_all	*out;
	int		i;

	out = malloc(sizeof(t_all));
	if (!out)
		return (err("MALLOC_ERROR all"));
	out->in = in;
	if (!init_sem(out, in))
		return (NULL);
	out->pid = malloc(sizeof(int) * in->amount);
	if (!out->pid)
		return (err_id(0, "MALLOC_ERROR all", out));
	i = 0;
	while (i < in->amount)
	{
		out->pid[i] = -1;
		i++;
	}
	if (!create_lst(out))
		return (err_id(0, NULL, out));
	return (out);
}

void	destroy_all(t_all *all)
{
	if (!all)
		return ;
	if (all->death)
		sem_close(all->death);
	if (all->eaten)
		sem_close(all->eaten);
	if (all->print)
		sem_close(all->print);
	if (all->forks)
		sem_close(all->forks);
	if (all->pid)
		free(all->pid);
	if (all->lst)
		destroy_lst(all->lst);
	free(all->in);
	free(all);
}
