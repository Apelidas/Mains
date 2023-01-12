/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:09:28 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/11 10:50:33 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grid	*create_grid_obj(void)
{
	t_grid	*new;

	new = malloc(sizeof(t_grid));
	if (!new)
		return (NULL);
	new->mlx = mlx_init();
	new->in = NULL;
	new->data = NULL;
	return (new);
}

int	free_grid_obj(t_grid *todel)
{
	free_row(todel->safe);
	free_data_obj(todel->data, todel->mlx);
	free_row(todel->in);
	free(todel);
	exit(0);
	return (0);
}

void	count_color(t_grid *m)
{
	t_row	*tmp;
	int		i;

	m->c_count = 0;
	tmp = m->in;
	while (tmp)
	{
		i = 0;
		while (tmp->row[i])
		{
			m->c_count++;
			i++;
		}
		tmp = tmp->next;
	}
}
