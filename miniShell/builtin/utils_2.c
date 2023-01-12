/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:47 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:47 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pwd_exist(t_env	*env)
{
	t_env	*current;

	current = env;
	while (current && compare_str(current->var[0], "PWD") != 0)
		current = current->next;
	if (compare_str(current->var[0], "PWD") == 0)
		return (0);
	else
		return (1);
}

void	change_old_pwd(t_env **env_list, char *value)
{
	t_env	*current;

	current = *env_list;
	while (current && compare_str(current->var[0], "OLDPWD") != 0)
		current = current->next;
	if (current && !value)
	{
		if (current->var[1])
		{
			free(current->var[1]);
			current->var[1] = NULL;
			current->env_str = change_env_str(current->env_str,
					current->var[0], NULL);
		}
	}
	else if (current && compare_str(current->var[0], "OLDPWD") == 0)
	{
		current->var = env_var_size(current->var, "OLDPWD");
		current->var[1] = ft_strdup(value);
		current->env_str = change_env_str(current->env_str,
				current->var[0], current->var[1]);
	}
}
