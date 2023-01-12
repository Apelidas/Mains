/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:53 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:54 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pathfinder(t_lst *lst, char **envp)
{
	if (!lst->cmd || !lst->cmd[0])
		return ;
	if (ft_strncmp(lst->cmd[0], "./", 2) == 0)
	{
		if (access(&(lst->cmd[0][2]), X_OK) != 0)
			return ;
		lst->path = malloc(sizeof(char) * (ft_strlen(lst->cmd[0]) + 1));
		if (!lst->path)
		{
			write(2, "MALLOC_ERROR pathfinder\n", 24);
			return ;
		}
		ft_strlcpy(lst->path, lst->cmd[0], ft_strlen(lst->cmd[0]) + 1);
		return ;
	}
	else if (lst->cmd[0][0] == '/')
	{
		lst->path = malloc(sizeof(char) * (ft_strlen(lst->cmd[0]) + 1));
		if (!lst->path)
			return ;
		ft_strlcpy(lst->path, lst->cmd[0], ft_strlen(lst->cmd[0]) + 1);
	}
	else
		lst->path = search_path(lst->cmd[0], envp);
}

char	*search_path(char *argv, char **envp)
{
	char	**path;
	char	*name;
	char	*help;
	int		i;

	path = locate_path(envp);
	if (!path)
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
	g_status = 127;
	free_split(path);
	return (NULL);
}

int	is_buildin(char *string)
{
	if (!string)
		return (0);
	if (ft_strncmp(string, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(string, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(string, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(string, "export", 7) == 0)
		return (1);
	if (ft_strncmp(string, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(string, "env", 4) == 0)
		return (1);
	if (ft_strncmp(string, "exit", 5) == 0)
		return (1);
	return (0);
}

void	*input_loop(char *split, char **envp, t_lst **lst)
{
	int		k;
	t_lst	*tmp;

	tmp = create_lst();
	lst_addback(lst, tmp);
	if (!search_arrow(&split, tmp))
		return (err_id(1, NULL, *lst));
	tmp->cmd = banana(split, ' ');
	if (!tmp->cmd)
		return (err_id(2, "MALLOC_ERROR split", *lst));
	clean_split(tmp->cmd);
	k = 0;
	while (tmp->cmd[k])
	{
		remove_quotes(tmp->cmd[k]);
		k++;
	}
	if (!is_buildin(tmp->cmd[0]))
		pathfinder(tmp, envp);
	else
		tmp->build = 1;
	return (NULL);
}

t_lst	*input_check(char *in, char **envp)
{
	t_lst	*out;
	char	**split;
	int		i;

	out = NULL;
	if (!pipe_fil(in))
		return (err("SYNTAX_ERROR near '|'"));
	split = banana(in, '|');
	if (!split)
		return (NULL);
	i = 0;
	replace(split, envp);
	while (split[i])
	{
		input_loop(split[i], envp, &out);
		i++;
	}
	free_split(split);
	return (out);
}
