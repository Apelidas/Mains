/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:57:55 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/19 16:40:22 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_helper(int *fd, int file)
{
	dup2(file, 0);
	dup2(fd[1], 1);
	close(file);
	close(fd[1]);
	close(fd[0]);
}

int	starter_badpid(char **command, char *path)
{
	free_split(command);
	free(path);
	write(2, "Fork failed\n", 12);
	return (-1);
}

int	child(t_input *data, char *path, char **command)
{
	execve(path, command, data->envp);
	write(2, "Command could not be executed\n", 30);
	exit(-1);
}
