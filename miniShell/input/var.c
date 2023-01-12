/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:35:35 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:35:35 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	quest(char **string, int pos)
{
	char	*tmp;

	tmp = ft_itoa(g_status);
	if (!tmp)
		return ;
	str_cut(*string, pos, pos + 2);
	*string = str_insert(*string, tmp, pos);
	if (!*string)
		return ;
}

/*
Variable rules: $([a-z || A-Z || _][a-z || A-Z || 0-9 || _]
First char is special from the rest
*/
void	replace_var(char **split, char **env, int k, int i)
{
	int		len;
	char	*string;

	if (k != -1)
	{
		if (split[i][k + 1] == '?')
		{
			quest(&split[i], k);
			return ;
		}
		len = find_var_end(&split[i][k + 1]);
		string = malloc(sizeof(char) * (len + 1));
		if (!string)
			malloc_exit();
		ft_strlcpy(string, &split[i][k + 1], len + 1);
		string = find_var(string, env, len);
		str_cut(split[i], k, len + k + 1);
		if (!string)
			return ;
		string = str_insert(split[i], string, k);
		if (string)
			split[i] = string;
		k++;
	}
}

void	replace(char **split, char **env)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	while (split[i] && i < 2)
	{
		pos = find_var_start(split[i]);
		while (pos != -1)
		{
			replace_var(split, env, pos, i);
			pos = find_var_start(split[i]);
		}
		i++;
	}
}

int	is_var(char tocheck)
{
	if (tocheck >= 'a' && tocheck <= 'z')
		return (1);
	if (tocheck >= 'A' && tocheck <= 'Z')
		return (1);
	if (tocheck == '_')
		return (1);
	return (0);
}
