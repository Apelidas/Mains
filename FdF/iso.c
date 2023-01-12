/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:28:04 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/12 17:29:29 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing(t_vector3d	*help, t_vector3d	*tmp, t_data *data)
{
	draw_line(help, tmp, data);
	free(help);
}

void	iso_line(t_row *in, t_data *data)
{
	t_vector3d	*tmp;
	t_vector3d	*help;
	int			i;

	while (in)
	{
		i = 0;
		help = NULL;
		while (in->row[i])
		{
			tmp = malloc(sizeof(t_vector3d));
			tmp->x = in->row[i]->x - in->row[i]->y;
			tmp->y = (in->row[i]->y + in->row[i]->x) / 2 - in->row[i]->z;
			tmp->z = in->row[i]->z;
			tmp->color = in->row[i]->color;
			i++;
			if (help)
				drawing(help, tmp, data);
			help = tmp;
		}
		free(help);
		in = in->next;
	}
}

void	calc_iso(t_row *in, t_vector3d *help, t_vector3d *tmp, t_data *data)
{
	int			i;
	t_row		*next;

	i = 0;
	next = in->next;
	while (in->row[i] && next->row[i])
	{
		tmp->x = in->row[i]->x - in->row[i]->y;
		tmp->y = (in->row[i]->y + in->row[i]->x) / 2 - in->row[i]->z;
		tmp->z = in->row[i]->z;
		tmp->color = in->row[i]->color;
		help->x = next->row[i]->x - next->row[i]->y;
		help->y = (next->row[i]->y + next->row[i]->x) / 2 - next->row[i]->z;
		help->z = next->row[i]->z;
		help->color = next->row[i]->color;
		draw_line(help, tmp, data);
		i++;
	}
}

void	iso_coloumn(t_row *in, t_data *data)
{
	t_vector3d	*tmp;
	t_vector3d	*help;

	help = malloc(sizeof(t_vector3d));
	tmp = malloc(sizeof(t_vector3d));
	while (in->next)
	{
		calc_iso(in, help, tmp, data);
		in = in->next;
	}
	free(tmp);
	free(help);
}

void	write_isometric(t_row *in, t_data *data)
{
	iso_line(in, data);
	iso_coloumn(in, data);
}
