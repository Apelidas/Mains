/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:11 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:11 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	help_change(char **check_env, t_env *current, char *str)
{
	if (!check_env[1])
		return (err_int_id(1, NULL, check_env));
	if (current->var[1])
	{
		free(current->var[1]);
		free(current->env_str);
		current->env_str = ft_strdup(str);
	}
	return (1);
}

static int	change_existing_var(t_env **env_list, char *str)
{
	t_env	*current;
	char	**check_env;

	check_env = env_and_value(str);
	if (!check_env)
		return (0);
	current = *env_list;
	while (current)
	{
		if (compare_str(current->var[0], check_env[0]) == 0)
		{
			if (!help_change(check_env, current, str))
				return (0);
			current->var[1] = ft_strdup(check_env[1]);
			free_splits(check_env);
			return (0);
		}
		else
			current = current->next;
	}
	free_splits(check_env);
	return (1);
}

void	export_add_arg(t_env **env_list, char *str)
{
	t_env	*element;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (is_var(str[i]) == 0)
		{
			print_stderror("export: not a valid identifier\n");
			g_status = 1;
			return ;
		}
		i++;
	}
	if (change_existing_var(env_list, str) == 0)
		return ;
	else
	{
		element = new_env_node(str);
		if (!element)
			return ;
		add_to_end(env_list, element);
	}
	g_status = 0;
}

/*
	We check if the argument is valid
	arguments that are allowed start with A-Z, a-z or '_'
	brackets can be removed, contained printf checks before
*/
void	export_arg(t_env *env_list, char **arg)
{
	int	index;

	index = 1;
	while (arg[index])
	{
		if (arg[index][0] >= 'A' && arg[index][0] <= 'Z')
		{
			export_add_arg(&env_list, arg[index]);
		}
		else if (arg[index][0] >= 'a' && arg[index][0] <= 'z')
		{
			export_add_arg(&env_list, arg[index]);
		}
		else if (arg[index][0] == '_')
		{
			export_add_arg(&env_list, arg[index]);
		}
		else
		{
			printf("export: `%s' not a valid identifier\n", arg[index]);
			g_status = 1;
		}
		index++;
	}
}
