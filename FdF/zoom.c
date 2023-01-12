/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:14:16 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/06 17:41:05 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	zoom_in(t_grid *grid)
{
	t_row	*tmp;
	int		i;

	grid->data->zoom += 0.2;
	if (grid->data->zoom == 1.0)
	{
		reset(grid);
		return ;
	}
	tmp = grid->in;
	while (tmp)
	{
		i = 0;
		while (tmp->row[i])
		{
			tmp->row[i]->x *= 1.2;
			tmp->row[i]->y *= 1.2;
			tmp->row[i]->z *= 1.2;
			i++;
		}
		tmp = tmp->next;
	}
}

void	zoom_out(t_grid *grid)
{
	t_row	*tmp;
	int		i;

	if (grid->data->zoom <= 0.0)
		return ;
	grid->data->zoom -= 0.2;
	if ((int) grid->data->zoom == 1.0)
	{
		reset(grid);
		return ;
	}
	tmp = grid->in;
	while (tmp)
	{
		i = 0;
		while (tmp->row[i])
		{
			tmp->row[i]->x *= 0.8;
			tmp->row[i]->y *= 0.8;
			tmp->row[i]->z *= 0.8;
			i++;
		}
		tmp = tmp->next;
	}
}

void	reset(t_grid *m)
{
	free_row(m->in);
	m->in = cpy_row(m->safe);
	m->data->zoom = 1;
	m->data->off_x = 960;
	m->data->off_y = 10;
	m->data->angle = 0;
}

t_row	*cpy_row(t_row *in)
{
	t_row	*out;
	t_row	*tmp;
	int		i;

	out = NULL;
	while (in)
	{
		tmp = create_row();
		tmp->row = create_vector_array(row_size(in) + 1);
		i = 0;
		while (in->row[i])
		{
			tmp->row[i] = create_vector3d();
			tmp->row[i]->x = in->row[i]->x;
			tmp->row[i]->y = in->row[i]->y;
			tmp->row[i]->z = in->row[i]->z;
			tmp->row[i]->color = in->row[i]->color;
			i++;
		}
		row_addback(&out, tmp);
		in = in->next;
	}
	return (out);
}

void	check_zoom(t_grid *grid)
{
	t_row	*in;
	int		i;

	in = grid->in;
	while (in)
	{
		i = 0;
		while (!check_borders(in->row[i], grid->data))
			zoom_out(grid);
		while (in->row[i])
			i++;
		while (!check_borders(in->row[i - 1], grid->data))
			zoom_out(grid);
		in = in->next;
	}
}
