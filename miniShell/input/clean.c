/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:28 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:30 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (split[i][0] == '\0')
		{
			free(split[i]);
			split[i] = NULL;
		}
		i++;
	}
}

int	white_pipe(char *string, int i)
{
	while (i > 0 && string[i] != '|')
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (1);
		i--;
	}
	return (0);
}

int	help_fil(char *string, int *i, int *count)
{
	if (string[*i] != '|')
		*count += 1;
	else if (string[*i] == '|' && *count == 0)
		return (0);
	else if (string[*i] == '|')
		*count = 0;
	if (string[*i])
		*i += 1;
	return (1);
}

int	pipe_fil(char *string)
{
	int	i;
	int	count;
	int	help;

	i = 0;
	count = 0;
	while (string[i])
	{
		help = skip_quotes(string, i);
		if (i != help)
			count++;
		i = help;
		i = skip_whitesp(string, i);
		if (!help_fil(string, &i, &count))
			return (0);
	}
	if (string[i - 1] == '|' && count == 0)
		return (0);
	if (!white_pipe(string, i - 1))
		return (0);
	return (1);
}

void	print_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("cmd-pointer:%p\n", &split[i]);
		printf("%d:<%s>\n", i, split[i]);
		i++;
	}
	printf("\n");
}
