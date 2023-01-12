/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:21:54 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/19 16:32:09 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_doc(char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
		return (-1);
	return (1);
}

int	bonus(int *fd, t_input *data, int read_end, int i)
{
	char	*path;
	char	**command;
	int		pid;

	command = ft_split(data->argv[i], ' ');
	if (!command)
		return (-1);
	path = search_path(command[0], data->envp);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(read_end, 0);
		dup2(fd[1], 1);
	}
	close(read_end);
	close(fd[1]);
	pid_check(data, pid, path, command);
	wait(NULL);
	free_split(command);
	free(path);
	if (pid < 0)
		return (-1);
	return (1);
}

int	bonus_pid_check(t_input *data, int *fd, int *file)
{
	char	*path;
	char	**command;
	int		pid;

	command = ft_split(data->argv[3], ' ');
	path = search_path(command[0], data->envp);
	pid = fork();
	if (pid < 0)
	{
		free_split(command);
		free(path);
		write(2, "Fork failed\n", 12);
		return (-1);
	}
	else if (pid == 0)
	{
		first_bonus(fd, file);
		child(data, path, command);
	}
	parent_free(fd, file, command, path);
	parent(data, file, 1);
	return (1);
}

int	bonus_starter(t_input *data)
{
	int		fd[2];
	char	*input;
	int		file[2];

	if (create_pipes(fd, file) < 0)
		return (-1);
	write(1, "Please give your input\n", 23);
	input = get_next_line(0);
	while (input != NULL
		&& ft_strncmp(input, data->argv[2], ft_strlen(data->argv[2])) != 0)
	{
		write(fd[1], input, ft_strlen(input));
		free(input);
		input = get_next_line(0);
	}
	free(input);
	if (bonus_pid_check(data, fd, file) == 1)
		return (1);
	return (-1);
}
