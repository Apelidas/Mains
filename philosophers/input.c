/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:01:57 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/27 16:18:35 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_error(void)
{
	write(2, "input is not a number\n", 22);
	return (-1);
}

int	input_check(int argc, char **argv, t_input *data)
{
	if (argc != 6 && argc != 5)
	{
		write(2, "Wrong amount of arguments\n", 26);
		return (-1);
	}
	data->die = ft_atoi(argv[1]);
	if (data->die == -1)
		return (write_error());
	data->eat = ft_atoi(argv[2]);
	if (data->eat == -1)
		return (write_error());
	data->sleep = ft_atoi(argv[3]);
	if (data->sleep == -1)
		return (write_error());
	data->die = ft_atoi(argv[4]);
	if (data->die == -1)
		return (write_error());
	if (argc == 6)
	{
		data->number = ft_atoi(argv[5]);
		if (data->number == -1)
			return (write_error());
	}
	return (1);
}

t_input	*create_input(void)
{
	t_input	*out;

	out = malloc(sizeof(t_input));
	if (!out)
	{
		write(2, "Malloc_ERROR\n", 13);
		return (NULL);
	}
	out->number = -1;
	return (out);
}

t_all	*create_all(void)
{
	t_all	*out;

	out = malloc(sizeof(t_all));
	if (!out)
		return (err("MALLOC_ERROR"));
	out->lst = NULL;
	out->in = create_input();
	if (!out->in)
	{
		free(out);
		return (err("MALLOC_ERROR"));
	}
	if (pthread_mutex_init(&out->death, NULL) != 0)
	{
		free(out);
		return (err("MUTEX_INIT_ERROR"));
	}
	return (out);
}

void	destroy_all(t_all *todel)
{
	if (!todel)
		return ;
	if (todel->lst)
		destroy_philo_list(todel->lst);
	if (todel->in)
		free(todel->in);
	pthread_mutex_destroy(&(todel->death));
	free(todel);
}
