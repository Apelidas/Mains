/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:30:32 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/06 17:42:11 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	*create_vector3d(void)
{
	t_vector3d	*new;

	new = malloc(sizeof(t_vector3d));
	if (!new)
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->color = 16777215;
	return (new);
}

void	free_vector3d(t_vector3d *todel)
{
	free(todel);
}

int	count_lines(t_row *start)
{
	t_row	*tmp;
	int		length;
	int		out;

	length = 0;
	tmp = start;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	out = 0;
	while (start->row[out])
		out++;
	if (length > out)
		return (length);
	return (out);
}

void	assign_x(t_row *start)
{
	double	length;
	int		i;

	length = count_lines(start);
	length = 980 / length;
	if (length < 3)
		length = 3;
	while (start)
	{
		i = 0;
		while (start->row[i])
		{
			start->row[i]->x = length * i;
			i++;
		}
		start = start->next;
	}
}

void	assign_y(t_row *start)
{
	double	length;
	int		i;
	int		count;

	length = count_lines(start);
	length = 980 / length;
	if (length < 3)
		length = 3;
	count = 0;
	while (start)
	{
		i = 0;
		while (start->row[i])
		{
			start->row[i]->y = length * count;
			i++;
		}
		start = start->next;
		count++;
	}
}
