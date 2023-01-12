/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:56:40 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/14 13:31:45 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"
# include "GNL/get_next_line.h"
# include <fcntl.h>

typedef struct s_vector3d
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_vector3d;

typedef struct s_row
{
	t_vector3d		**row;
	struct s_row	*next;
}				t_row;

typedef struct s_data
{
	char	*addr;
	void	*win;
	void	*img;
	int		bpp;
	int		l_length;
	int		endian;
	int		off_x;
	int		off_y;
	int		angle;
	double	zoom;
}				t_data;

typedef struct s_grid
{
	void	*mlx;
	t_row	*in;
	t_data	*data;
	t_row	*safe;
	int		c_count;
}				t_grid;

//			Object-Creation
t_data		*create_data_obj(void *mlx);
void		free_data_obj(t_data *img, void *mlx);
t_grid		*create_grid_obj(void);
int			free_grid_obj(t_grid *todel);
t_vector3d	*create_vector3d(void);
void		free_vector3d(t_vector3d *todel);
t_row		*create_row(void);
void		free_row(t_row *todel);

//			Input-Handling
int			deter_line_length(char **in);
t_row		*inter_input(char **in);
t_row		*read_inter_file(char *name);
void		assign_x(t_row *start);
void		assign_y(t_row *start);
void		count_color(t_grid *m);
void		assign_color(t_grid *m);

//			MISC
t_vector3d	**create_vector_array(int size);
void		row_addback(t_row **list, t_row *toadd);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		write_isometric(t_row *in, t_data *data);
void		draw_line(t_vector3d *a, t_vector3d *b, t_data *data);
int			color_to_int(char *in);
int			get_color(t_vector3d *a, t_vector3d *b, t_vector3d *vec);
void		rotate(t_row *in, t_data *data);
void		put_pixel(t_data *d, t_vector3d *a, int col);
void		zoom_in(t_grid *grid);
void		zoom_out(t_grid *grid);
void		reset(t_grid *m);
t_row		*cpy_row(t_row *in);
int			check_dist_min(t_vector3d *a, t_vector3d *b, t_data *data);
int			row_size(t_row *in);
int			count_lines(t_row *start);
void		check_zoom(t_grid *grid);
int			check_borders(t_vector3d *vec, t_data *data);

//			Debug
void		print_rows(t_row *out);
void		print_vector(t_vector3d *a);

#endif