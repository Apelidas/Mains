/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:14:09 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/19 16:37:30 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_bonus(int *fd, int *file)
{
	dup2(fd[0], 0);
	dup2(file[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(file[0]);
	close(file[1]);
}

void	parent_free(int *fd, int *file, char **command, char *path)
{
	close(fd[0]);
	close(fd[1]);
	close(file[1]);
	free_split(command);
	free(path);
}

int	create_pipes(int *fd, int *file)
{
	int	pid;

	pid = pipe(fd);
	if (pid < 0)
	{
		write(2, "Pipe creation failed\n", 21);
		return (-1);
	}
	pid = pipe(file);
	if (pid < 0)
	{
		write(2, "Pipe creation failed\n", 21);
		return (-1);
	}
	return (pid);
}
