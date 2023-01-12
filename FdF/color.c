/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:34:41 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/11 10:50:29 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_to_int(char *in)
{
	int	out;

	in = in + 2;
	out = 0;
	while (*in)
	{
		if (*in == '\n')
			break ;
		out = out * 16;
		if (in[0] >= '0' && in[0] <= '9')
			out += in[0] - '0';
		else if (in[0] >= 'a' && in[0] <= 'f')
			out += in[0] - 'a' + 10;
		else
			out += in[0] - 'A' + 10;
		in++;
	}
	return (out);
}

int	get_color(t_vector3d *a, t_vector3d *b, t_vector3d *vec)
{
	if (vec->x == a->x && vec->y == a->y)
		return (a->color);
	if (vec->x == b->x && vec->y == b->y)
		return (b->color);
	return (a->color);
}

void	assign_color(t_grid *m)
{
	t_row	*tmp;
	int		i;

	tmp = m->in;
	while (tmp && m->c_count == 0)
	{
		i = 0;
		while (tmp->row[i])
		{
			if (tmp->row[i]->z > 0)
				tmp->row[i]->color = 0x00ff0000;
			else if (tmp->row[i]->z < 0)
				tmp->row[i]->color = 0x000000ff;
			i++;
		}
		tmp = tmp->next;
	}
}
