/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:35 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:35 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_int(char *message)
{
	if (!message)
		return (0);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	return (0);
}

void	*err(char *message)
{
	if (!message)
		return (NULL);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	g_status = -1;
	return (NULL);
}

int	err_int_id(int id, char *message, void *todel)
{
	if (id == 0)
	{
		free(todel);
		return (err_int(message));
	}
	else if (id == 1)
	{
		free_split((char **) todel);
		return (err_int(message));
	}
	else if (id == 2)
	{
		destroy_lst(todel);
		return (err_int(message));
	}
	return (0);
}

void	*err_id(int id, char *message, void *todel)
{
	if (id == 0)
	{
		free(todel);
		return (err(message));
	}
	else if (id == 1)
	{
		destroy_lst(todel);
		return (NULL);
	}
	else if (id == 2)
	{
		free_split((char **) todel);
		return (NULL);
	}
	else if (id == 3)
	{
		g_status = -1;
		return (err(message));
	}
	return (NULL);
}
