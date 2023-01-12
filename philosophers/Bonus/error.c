/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:10:14 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/13 15:56:13 by kkleinsc         ###   ########.fr       */
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

void	*err_id(int err_id, char *message, void *todel)
{
	if (err_id == 0)
	{
		destroy_all((t_all *) todel);
		return (err(message));
	}
	else if (err_id == 1)
	{
		destroy_lst((t_philo *) todel);
		return (err(message));
	}
	else if (err_id == 2)
	{
		return (err(message));
	}
	else if (err_id == 3)
	{
		free(todel);
		return (err(message));
	}
	return (NULL);
}

int	err_int(char *message)
{
	err(message);
	return (0);
}
