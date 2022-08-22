/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:28:45 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/22 10:43:18 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_input	*create_input(char **argv, int argc, char **envp)
{
	t_input	*new;

	new = malloc (sizeof(t_input));
	if (!new)
		return (NULL);
	new->argv = argv;
	new->argc = argc;
	new->envp = envp;
	return (new);
}

int	input_check(int argc, char **argv)
{
	int	fd;

	if (argc < 5)
	{
		write(2, "Wrong Amount of Arguments\n", 26);
		return (0);
	}
	if (check_doc(argv) < 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(2, "Input File doesn't exist\n", 25);
			return (0);
		}
		close(fd);
	}
	fd = open(argv[argc - 1], O_WRONLY);
	if (fd < 0)
		fd = open(argv[argc - 1], O_CREAT, S_IRWXU);
	close(fd);
	return (1);
}

static int	path_helper(char **envp, char ***path)
{
	int	i;

	i = locate_path(envp);
	if (i < 0)
		return (-1);
	*path = ft_split(envp[i], ':');
	if (!path)
		return (-1);
	return (1);
}

char	*search_path(char *argv, char **envp)
{
	char	**path;
	char	*name;
	char	*help;
	int		i;

	if (path_helper(envp, &path) < 0)
		return (NULL);
	i = 0;
	while (path[i])
	{
		help = ft_strjoin(path[i], "/");
		name = ft_strjoin(help, argv);
		free(help);
		if (access(name, F_OK) == 0)
		{
			free_split(path);
			return (name);
		}
		i++;
		free(name);
	}
	free_split(path);
	return (NULL);
}

int	check_paths(t_input *data)
{
	int		i;
	char	*path;
	char	**help;

	if (check_doc(data->argv) == 1)
		i = 3;
	else
		i = 2;
	path = NULL;
	while (i < data->argc - 1)
	{
		help = ft_split(data->argv[i], ' ');
		path = search_path(help[0], data->envp);
		free_split(help);
		if (!path)
		{
			write(2, "Path could not be found\n", 24);
			return (0);
		}
		i++;
		free(path);
	}
	return (1);
}
