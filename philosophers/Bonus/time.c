/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:26:58 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/12 14:27:21 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_ms(struct timeval *time)
{
	long int	out;

	if (!time)
		return (-1);
	out = (long int) time->tv_sec;
	out = out * 1000;
	out += ((long int) time->tv_usec) / 1000;
	return (out);
}

long int	get_time(void)
{
	struct timeval	time;
	long int		out;

	out = 0;
	if (gettimeofday(&time, NULL) != 0)
		return (err_int("TIME_ERROR get"));
	out = get_ms(&time);
	return (out);
}
