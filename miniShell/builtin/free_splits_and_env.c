/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splits_and_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:20 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:20 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(t_env *list)
{
	t_env	*head;
	t_env	*tmp;

	head = list;
	while (head != NULL)
	{
		if (head->env_str)
			free(head->env_str);
		tmp = head;
		head = head->next;
		if (tmp->var)
			free_splits(tmp->var);
		free(tmp);
	}
}

void	free_splits(char **splits)
{
	int	i;

	i = 0;
	if (!splits)
		return ;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free (splits);
}
