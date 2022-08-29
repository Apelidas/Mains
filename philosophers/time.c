/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:31:44 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/29 13:34:42 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

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