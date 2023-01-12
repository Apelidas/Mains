/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:18:57 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/05 17:19:03 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*create_data_obj(void *mlx)
{
	t_data	*n;

	n = malloc (sizeof(t_data));
	if (!n)
		return (NULL);
	n->img = mlx_new_image(mlx, 1920, 1080);
	n->win = mlx_new_window(mlx, 1920, 1080, "fdf");
	n->addr = mlx_get_data_addr(n->img, &n->bpp, &n->l_length, &n->endian);
	n->off_x = 960;
	n->off_y = 50;
	n->angle = 0;
	n->zoom = 1.0;
	return (n);
}

void	free_data_obj(t_data *img, void *mlx)
{
	mlx_destroy_image(mlx, img->img);
	mlx_destroy_window(mlx, img->win);
	free(img);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data *d, t_vector3d *a, int col)
{
	my_mlx_pixel_put(d, a->x + d->off_x, a->y + d->off_y, col);
}
