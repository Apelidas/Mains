/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:13:57 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/22 10:38:06 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pid_check(t_input *data, int pid, char *path, char **command)
{
	if (pid < 0)
	{
		write(2, "Fork failed\n", 12);
		return (-1);
	}
	else if (pid == 0)
	{
		pid = child(data, path, command);
		if (pid < 0)
			exit (0);
	}
	return (1);
}

int	ending(t_input *data, int *fd)
{
	char	**command;
	char	*path;
	int		file;
	int		pid;

	command = ft_split(data->argv[data->argc - 2], ' ');
	path = search_path(command[0], data->envp);
	file = open(data->argv[data->argc - 1], O_WRONLY);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], 0);
		dup2(file, 1);
		close(fd[1]);
		close(fd[0]);
		close(file);
	}
	pid = pid_check(data, pid, path, command);
	free_split(command);
	free(path);
	close(file);
	close(fd[0]);
	if (pid < 0)
		return (-1);
	return (1);
}

int	parent(t_input *data, int *fd, int bon)
{
	int		i;
	int		pid;

	i = 3 + bon;
	while (i < data->argc - 2)
	{
		pid = bonus(fd, data, fd[0], i);
		if (pid < 0)
			return (-1);
		i++;
	}
	pid = ending(data, fd);
	return (1);
}
