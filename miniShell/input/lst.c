/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:57 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:57 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*create_lst(void)
{
	t_lst	*out;

	out = malloc(sizeof(t_lst));
	if (!out)
		return (err("MALLOC_ERROR create_lst"));
	out->cmd = NULL;
	out->path = NULL;
	out->delim = NULL;
	out->fd_in = 0;
	out->fd_out = 1;
	out->append = 0;
	out->build = 0;
	out->next = NULL;
	out->prev = NULL;
	return (out);
}

void	lst_addback(t_lst **start, t_lst *toadd)
{
	t_lst	*tmp;

	if (!*start)
	{
		*start = toadd;
		return ;
	}
	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = toadd;
	toadd->prev = tmp;
}

void	destroy_lst(t_lst *start)
{
	t_lst	*tmp;

	while (start->prev)
		start = start->prev;
	while (start)
	{
		tmp = start;
		start = start->next;
		if (tmp->delim)
			free(tmp->delim);
		if (tmp->path)
			free(tmp->path);
		if (tmp->cmd)
			free_split(tmp->cmd);
		free(tmp);
	}
}

void	print_lst(t_lst *start)
{
	if (!start)
		return ;
	while (start)
	{
		printf("cmd:\n");
		print_split(start->cmd);
		printf(":\n");
		printf("Path:%s\ndelim:%s\nin:%d |out:%d |append:%d\n\n",
			start->path, start->delim, start->fd_in,
			start->fd_out, start->append);
		start = start->next;
	}
}

int	lst_len(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
