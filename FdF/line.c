/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:26:29 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/06 17:23:46 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_borders(t_vector3d *vec, t_data *data)
{
	if (vec->x + data->off_x >= 1920 || vec->x + data->off_x <= 0)
		return (0);
	if (vec->y + data->off_y >= 1080 || vec->y + data->off_y <= 0)
		return (0);
	return (1);
}

int	check_dist_min(t_vector3d *a, t_vector3d *b, t_data *data)
{
	double	x;
	double	y;
	double	dist;

	x = a->x - b->x;
	y = a->y - b->y;
	if (x < 0)
		x = x *(-1);
	if (y < 0)
		y = y * (-1);
	dist = sqrt((x * x) + (y * y));
	dist *= data->zoom;
	if (dist < 3)
		return (1);
	return (0);
}

void	clean_line(t_vector3d *tmp, t_vector3d *vec, t_data *data)
{
	if (tmp->x != 0)
	{
		while (tmp->y < vec->y - 1 || tmp->y > vec->y + 1)
		{
			if (tmp->y < vec->y)
				tmp->y++;
			else
				tmp->y--;
			if (check_borders(tmp, data))
				put_pixel(data, tmp, 0x00ffffff);
		}
	}
}

int	deter_function(t_vector3d *a, t_vector3d *b, double *m, t_vector3d *vec)
{
	int	max;

	*m = (a->y - b->y) / (double)(a->x - b->x);
	if (a->x < b->x)
	{
		max = b->x;
		vec->x = a->x;
	}
	else
	{
		max = a->x;
		vec->x = b->x;
	}
	return (max);
}

void	draw_line(t_vector3d *a, t_vector3d *b, t_data *data)
{
	t_vector3d	*vec;
	t_vector3d	*tmp;
	int			max;
	double		m;
	double		n;

	vec = malloc(sizeof(t_vector3d));
	tmp = malloc(sizeof(t_vector3d));
	tmp->x = 0;
	max = deter_function(a, b, &m, vec);
	n = a->y - (a->x * m);
	while (vec->x < max)
	{
		vec->y = (vec->x * m) + n;
		clean_line(tmp, vec, data);
		if (check_borders(vec, data))
			put_pixel(data, vec, get_color(a, b, vec));
		tmp->x = vec->x;
		tmp->y = vec->y;
		vec->x++;
	}
	free(tmp);
	free(vec);
}
