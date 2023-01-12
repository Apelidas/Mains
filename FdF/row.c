/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:22:49 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/05 21:10:13 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	**create_vector_array(int size)
{
	t_vector3d	**new;

	new = ft_calloc(size + 1, sizeof(t_vector3d *));
	if (!new)
		return (NULL);
	new[size] = NULL;
	return (new);
}

t_row	*create_row(void)
{
	t_row	*new;

	new = ft_calloc(1, sizeof(t_row));
	if (!new)
		return (NULL);
	new->row = NULL;
	new->next = NULL;
	return (new);
}

void	free_row(t_row *todel)
{
	int	i;

	i = 0;
	while (todel->row[i])
	{
		free(todel->row[i]);
		i++;
	}
	free(todel->row);
	if (todel->next)
		free_row(todel->next);
	free(todel);
}

void	row_addback(t_row **list, t_row *toadd)
{
	t_row	*help;

	help = *list;
	if (!help)
	{
		*list = toadd;
		return ;
	}
	while (help->next)
		help = help->next;
	help->next = toadd;
}

int	row_size(t_row *in)
{
	int	out;

	out = 0;
	while (in->row[out])
		out++;
	return (out);
}
