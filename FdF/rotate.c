/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:54:18 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/05 21:07:41 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_even(t_row *in)
{
	int			i;
	t_vector3d	*start;

	start = in->row[0];
	while (in)
	{
		i = 0;
		while (in->row[i])
		{
			if (start != in->row[i])
				in->row[i]->y = 0 - in->row[i]->y;
			i++;
		}
		in = in->next;
	}
}

void	rot_uneven(t_row *in)
{
	int			i;
	t_vector3d	*start;

	start = in->row[0];
	while (in)
	{
		i = 0;
		while (in->row[i])
		{
			if (start != in->row[i])
				in->row[i]->x = 0 - in->row[i]->x;
			i++;
		}
		in = in->next;
	}
}

void	correct_off(t_data *data)
{
	if (data->angle == 270)
	{
		data->off_x = 10;
		data->off_y = 540;
	}
	else if (data->angle == 180)
	{
		data->off_x = 960;
		data->off_y = 1070;
	}
	else if (data->angle == 90)
	{
		data->off_x = 1910;
		data->off_y = 540;
	}
	else
	{
		data->off_x = 960;
		data->off_y = 10;
	}
}

void	rotate(t_row *in, t_data *data)
{
	if (data->angle < 0)
		data->angle = 360 + data->angle;
	else if (data->angle >= 360)
		data->angle = 0;
	if (data->angle == 90 || data->angle == 270)
		rot_uneven(in);
	else
		rot_even(in);
	correct_off(data);
}
