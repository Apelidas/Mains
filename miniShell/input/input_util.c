/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:47 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:49 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**locate_path(char **envp)
{
	int		help;
	int		i;
	char	**out;

	help = 0;
	i = 1;
	while (envp[help] && i != 0)
	{
		i = ft_strncmp(envp[help], "PATH=", 5);
		if (i == 0)
			break ;
		help++;
	}
	if (i != 0)
	{
		return (NULL);
	}
	out = ft_split(envp[help], ':');
	return (out);
}

void	free_split(char **tofree)
{
	int	i;

	i = 0;
	if (!tofree)
		return ;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

int	open_path(char *name)
{
	int	out;

	if (ft_strncmp(name, "here_doc", 9) == 0)
		return (0);
	if (access(name, F_OK) != 0)
		return (-1);
	out = open(name, O_RDONLY);
	return (out);
}

int	skip_quotes(char *string, int i)
{
	char	quote;

	if (string[i] == '"' || string[i] == 39)
	{
		quote = string[i];
		i++;
		while (string[i] && string[i] != quote)
			i++;
	}
	return (i);
}

int	skip_whitesp(char *string, int i)
{
	while (string[i] == ' ' || string[i] == '\t')
		i++;
	return (i);
}
