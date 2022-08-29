/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:10:14 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/27 16:09:01 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*err(char *out)
{
	write(2, out, ft_strlen(out));
	write(2, "\n", 1);
	return (NULL);
}

void	*philo_err(t_philo *todel, char *out)
{
	destroy_philo(todel);
	err(out);
	return (NULL);
}

void	*philo_lst_err(t_philo *start, char *out)
{
	destroy_philo_list(start);
	err(out);
	return (NULL);
}
