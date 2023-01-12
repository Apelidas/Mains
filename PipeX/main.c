/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:48:21 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/30 11:24:56 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	piper(int *fd, int *file, t_input *data)
{
	int	check;

	check = pipe(fd);
	if (check < 0)
	{
		write(2, "Piper didn't reach Hamelin\n", 27);
		return (-1);
	}
	*file = open(data->argv[1], O_RDONLY);
	return (1);
}

void	starter_helper(int *fd, int file, t_input *data)
{
	close(fd[1]);
	wait(NULL);
	close(file);
	parent(data, fd, 0);
}

void	starter_free(char **command, char *path)
{
	free_split(command);
	free(path);
}

int	starter(t_input *data)
{
	char	*path;
	char	**command;
	int		fd[2];
	int		pid;
	int		file;

	command = ft_split(data->argv[2], ' ');
	path = search_path(command[0], data->envp);
	pid = piper(fd, &file, data);
	if (pid < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (starter_badpid(command, path));
	else if (pid == 0)
	{
		child_helper(fd, file);
		child(data, path, command);
	}
	starter_helper(fd, file, data);
	starter_free(command, path);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_input	*data;

	if (input_check(argc, argv) == 0)
		return (0);
	data = create_input(argv, argc, envp);
	if (check_paths(data) == 0)
	{
		free(data);
		return (0);
	}
	if (check_doc(argv) == 1 && argc >= 6)
		bonus_starter(data);
	else
		starter(data);
	free(data);
	return (0);
}
