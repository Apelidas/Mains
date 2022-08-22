/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:34:11 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/18 11:22:18 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	locate_path(char **envp)
{
	int	out;
	int	i;

	out = 0;
	i = 1;
	while (envp[out] && i != 0)
	{
		i = ft_strncmp(envp[out], "PATH=", 5);
		if (i == 0)
			break ;
		out++;
	}
	if (i != 0)
	{
		return (-1);
	}
	return (out);
}

void	free_split(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}
