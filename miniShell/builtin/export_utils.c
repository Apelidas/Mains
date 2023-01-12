/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:15 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:15 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_size(t_env *list)
{
	t_env	*current;
	int		nbr_elements;

	current = list;
	nbr_elements = 0;
	while (current)
	{
		nbr_elements++;
		current = current->next;
	}
	return (nbr_elements);
}

void	reset_index(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		current->check = 0;
		current = current->next;
	}
}

void	add_index(t_env *env)
{
	int		list_size;
	char	*biggest;
	t_env	*current;

	biggest = NULL;
	list_size = check_size(env);
	while (list_size > 0)
	{
		current = env;
		biggest = unchecked_str(env, biggest);
		if (biggest == NULL)
			return ;
		current = env;
		while (compare_str(current->env_str, biggest) != 0)
		{
			current = current->next;
		}
		current->index = list_size;
		list_size--;
		current->check = 1;
	}
}
