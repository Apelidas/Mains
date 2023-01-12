/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:56:26 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/12/10 20:53:27 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	events(int key, t_grid *m)
{
	if (key == 53)
		free_grid_obj(m);
	else if (key == 13 || key == 126)
		m->data->off_y -= 10;
	else if (key == 0 || key == 123)
		m->data->off_x -= 10;
	else if (key == 1 || key == 125)
		m->data->off_y += 10;
	else if (key == 2 || key == 124)
		m->data->off_x += 10;
	else if (key == 15)
	{
		m->data->angle += 90;
		rotate(m->in, m->data);
	}
	else if (key == 34)
		zoom_in(m);
	else if (key == 31)
		zoom_out(m);
	else if (key == 51)
		reset(m);
	mlx_destroy_image(m->mlx, m->data->img);
	m->data->img = mlx_new_image(m->mlx, 1920, 1080);
	write_isometric(m->in, m->data);
	return (0);
}

int	mlx_runner(t_grid *m)
{
	mlx_put_image_to_window(m->mlx, m->data->win, m->data->img, 0, 0);
	return (1);
}

int	check_file(char *file)
{
	int	fd;
	int	out;

	out = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		out = 1;
	close(fd);
	return (out);
}

int	main(int argc, char **argv)
{
	t_grid	*m;

	if (argc != 2 || check_file(argv[1]))
	{
		write(2, "Wrong Input\n", 12);
		return (0);
	}
	m = create_grid_obj();
	m->in = read_inter_file(argv[1]);
	if (!m->in)
		return (0);
	m->safe = cpy_row(m->in);
	m->data = create_data_obj(m->mlx);
	count_color(m);
	assign_color(m);
	check_zoom(m);
	write_isometric(m->in, m->data);
	mlx_put_image_to_window(m->mlx, m->data->win, m->data->img, 0, 0);
	mlx_hook(m->data->win, 2, 1L << 0, events, m);
	mlx_hook(m->data->win, 17, 0, free_grid_obj, m);
	mlx_loop_hook(m->mlx, mlx_runner, m);
	mlx_loop(m->mlx);
	free_grid_obj(m);
}
