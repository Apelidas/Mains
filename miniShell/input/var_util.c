/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:35:23 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:35:23 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_var_start(char *in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		if (in[i] == 39)
		{
			i++;
			while (in[i] && in[i] != 39)
				i++;
		}
		else
		{
			if (in[i] == '$' && (is_var(in[i + 1]) || in[i + 1] == '?'))
				return (i);
			i++;
		}
	}
	return (-1);
}

int	find_var_end(char *in)
{
	int	i;

	i = 0;
	while (is_var(in[i]) || (in[i] >= '0' && in[i] <= '9'))
		i++;
	return (i);
}

char	*find_var(char *string, char **env, int len)
{
	int		i;
	int		k;
	char	*out;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(string, env[i], len) == 0)
			break ;
		i++;
	}
	if (!env[i])
		return (err_id(0, NULL, string));
	k = ft_strlen(&env[i][len + 1]);
	out = malloc(sizeof(char) * (k + 1));
	if (!out)
		return (err("MALLOC_ERROR find_var"));
	out[k] = '\0';
	while (k > 0)
	{
		k--;
		out[k] = env[i][k + len + 1];
	}
	free(string);
	return (out);
}

char	*str_insert(char *string, char *toadd, int pos)
{
	int		i;
	int		len;
	int		size;
	char	*out;

	i = -1;
	if (!string || !toadd)
		return (NULL);
	size = ft_strlen(string);
	len = ft_strlen(toadd);
	out = malloc (sizeof(char) * (size + len + 1));
	if (!out)
		return (err("MALLOC_ERROR insert"));
	while (++i < pos)
		out[i] = string[i];
	i--;
	while (++i - pos < len)
		out[i] = toadd[i - pos];
	i--;
	while (++i < size + len)
		out[i] = string[i - len];
	out[i] = '\0';
	free(string);
	free(toadd);
	return (out);
}

void	str_cut(char *string, int start, int end)
{
	int	i;

	i = 0;
	while (string[i + end])
	{
		string[start + i] = string[end + i];
		i++;
	}
	string[start + i] = '\0';
}
