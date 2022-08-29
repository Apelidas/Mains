/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:59:32 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/29 13:31:37 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_all *all)
{
	struct timeval time;
	
	if (gettimeofday(time, NULL) == -1)
		return (err("TIME_ERROR"));
	
}

int	main(int argc, char **argv)
{
	t_all	*data;

	data = create_all();
	if (input_check(argc, argv, data->in) == -1)
	{
		destroy_all(data);
		return (0);
	}
	//add programm here
	destroy_all(data);
	return (0);
}
