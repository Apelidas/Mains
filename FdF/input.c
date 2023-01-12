/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:33:47 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/07/06 17:07:02 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deter_line_length(char **in)
{
	int	count;

	count = 0;
	while (in[count])
		count++;
	return (count);
}

char	**check_string(char *in)
{
	char	**test;

	test = ft_split(in, ',');
	if (test[1])
		return (test);
	free(test);
	return (NULL);
}

void	check_incolor(t_row *row, int i, char **in)
{
	long int	num;
	char		**check;

	check = NULL;
	check = ft_split(in[i], ',');
	num = ft_atoi(in[i]);
	if (num < -2147483648 || num > 2147483647)
	{
		write(2, "Input out of range\n", 19);
		return ;
	}
	row->row[i] = create_vector3d();
	row->row[i]->z = (int) num;
	if (check && check[0] && check[1])
	{
		row->row[i]->color = color_to_int(check[1]);
		free(check[1]);
	}
	free(check[0]);
	free(check);
	free(in[i]);
}

t_row	*inter_input(char **in)
{
	int			i;
	t_row		*row;

	i = 0;
	row = create_row();
	if (!row)
		return (NULL);
	row->row = create_vector_array(deter_line_length(in));
	while (in[i])
	{
		check_incolor(row, i, in);
		i++;
	}
	free(in);
	return (row);
}

t_row	*read_inter_file(char *name)
{
	int		fd;
	char	*line;
	t_row	*in;
	t_row	*help;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	in = NULL;
	while (line)
	{
		help = inter_input(ft_split(line, ' '));
		if (!help)
			return (NULL);
		row_addback(&in, help);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	assign_x(in);
	assign_y(in);
	return (in);
}
