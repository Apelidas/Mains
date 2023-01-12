/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:51 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:51 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
@compare string returns 1 if the first string is smaller than the second one
	else 0 in case of same string or -1 if it is smaller
 */
int	compare_str(const char *st1, const char *st2)
{
	size_t	i;

	i = 0;
	while (st1[i])
	{
		if (!st2[i])
			return (1);
		if (st1[i] > st2[i])
			return (1);
		else if (st1[i] < st2[i])
			return (-1);
		else
			i++;
	}
	if (!st1[i] && st2[i])
		return (-1);
	return (0);
}

/*
	If env_value changes the whole env str needs to be manually changed 
	full = env_var + "=" + value*/
char	*change_env_str(char	*env_str, char *env_var, char *value)
{
	char	*tmp;
	char	*full;

	if (!value)
	{
		free(env_str);
		tmp = ft_strdup(env_var);
		return (tmp);
	}
	tmp = ft_strjoin(env_var, "=");
	if (value == 0)
		return (tmp);
	full = ft_strjoin(tmp, value);
	free(tmp);
	return (full);
}

void	print_stderror(const char *str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
}

int	check_split_size(char **cmd)
{
	int	size;

	size = 0;
	if (!cmd)
		return (0);
	while (cmd[size])
		size++;
	return (size);
}

char	**env_var_size(char **env_var, char *var)
{
	char	*tmp;
	char	**new_env_var;

	tmp = ft_strdup(var);
	free_splits(env_var);
	new_env_var = ft_calloc(3, sizeof(char *));
	new_env_var[0] = ft_strdup(tmp);
	free(tmp);
	return (new_env_var);
}
