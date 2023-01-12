/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:01:57 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 11:17:55 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_error(void)
{
	write(2, "input is not a number\n", 22);
	return (-1);
}

int	input_help(int argc, char **argv, t_input *data)
{
	data->eat = ft_atoi(argv[3]);
	if (data->eat == -1)
		return (err_int("INPUT_ERROR eat"));
	data->sleep = ft_atoi(argv[4]);
	if (data->sleep == -1)
		return (err_int("INPUT_ERROR sleep"));
	if (argc == 6)
	{
		data->number = ft_atoi(argv[5]);
		if (data->number == -1)
			return (err_int("INPUT_ERROR times"));
	}
	else
		data->number = -1;
	return (1);
}

int	input_check(int argc, char **argv, t_input **data)
{
	if (argc != 6 && argc != 5)
	{
		write(2, "Wrong amount of arguments\n", 26);
		return (-1);
	}
	*data = create_input();
	if (!*data)
		return (err_int("MALLOC_ERROR in"));
	(*data)->amount = ft_atoi(argv[1]);
	if ((*data)->amount == -1)
		return (err_int("INPUT_ERROR amount"));
	(*data)->die = ft_atoi(argv[2]);
	if ((*data)->die == -1)
		return (err_int("INPUT_ERROR die"));
	if (!input_help(argc, argv, *data))
		return (0);
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

int	check_zero(t_all *data)
{
	if (data->in->amount <= 0)
		return (err_int("Food went cold. Nobody showed up"));
	if (data->in->die <= 0)
		return (err_int("They are dead"));
	if (data->in->sleep <= 0)
		return (err_int("No time to sleep"));
	if (data->in->eat <= 0)
		return (err_int("You won the eating contest"));
	return (1);
}
