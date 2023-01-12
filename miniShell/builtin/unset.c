/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:44 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:44 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_node(t_env *node)
{
	int	i;

	i = 0;
	if (!node)
		return ;
	i = 0;
	while (i < 2 && node->var[i] != NULL)
	{
		free(node->var[i]);
		i++;
	}
	free(node->var);
	free(node->env_str);
}

void	unset_cmd_found(t_env *current)
{
	t_env	*tmp;

	tmp = current->next;
	if (current->next->next != NULL)
		current->next = current->next->next;
	else
		current->next = NULL;
	free_env_node(tmp);
	free(tmp);
	current = current->next;
}

void	check_env(t_env *current, char **unset, int i)
{
	while (current && current->next)
	{
		if (compare_str(current->next->var[0], unset[i]) == 0)
		{
			unset_cmd_found(current);
		}
		else
			current = current->next;
	}
}

void	unset_cmd(t_env **env_list, char **unset)
{
	int		i;
	t_env	*current;
	t_env	*tmp;

	i = 1;
	current = *env_list;
	while (unset[i])
	{
		check_env(current, unset, i);
		current = *env_list;
		if (compare_str(current->var[0], unset[i]) == 0)
		{
			tmp = (*env_list);
			*env_list = (*env_list)->next;
			free_env_node(tmp);
			current = *env_list;
		}
		i++;
	}
	g_status = 0;
}
