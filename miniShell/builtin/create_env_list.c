/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:32:48 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:32:48 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* last element of the list */
t_env	*last_node(t_env *head)
{
	t_env	*tmp;

	tmp = head;
	if (!head)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	add_to_end(t_env **list, t_env *new)
{
	t_env	*n;

	if (*list != NULL)
	{
		n = last_node(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

/* printf to show the VALUE of the VARIABLE of the list.
should be removed, when no testing is needed. */
t_env	*new_env_node(char *str)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(*new_env));
	if (!new_env)
		malloc_exit();
	new_env->env_str = ft_strdup(str);
	if (!new_env->env_str)
		return (err_id(0, "MALLOC_ERROR new_node", new_env));
	new_env->var = env_and_value(str);
	if (!new_env->var)
	{
		free(new_env->env_str);
		return (err_id(0, "MALLOC_ERROR new node", new_env));
	}
	new_env->check = 0;
	new_env->next = NULL;
	return (new_env);
}

void	create_env_list(t_env **env, char **envp)
{
	int		index;
	t_env	*element;

	index = 0;
	while (envp[index])
	{
		element = new_env_node(envp[index]);
		add_to_end(env, element);
		index++;
	}
}

void	env_cmd(t_env *env_list, char **cmd)
{
	int	cmd_count;

	cmd_count = 0;
	while (cmd[cmd_count])
		cmd_count++;
	if (cmd_count == 1)
		print_env(env_list);
	else
	{
		print_stderror("env: No arguments needed");
		g_status = 1;
	}
}
