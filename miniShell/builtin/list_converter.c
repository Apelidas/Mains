/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:24 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:24 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_size_value(t_env *list)
{
	t_env	*current;
	int		nbr_elements;

	current = list;
	nbr_elements = 0;
	while (current)
	{
		if (current->var[1])
			nbr_elements++;
		current = current->next;
	}
	return (nbr_elements);
}

char	**list_convert_export(t_env *env)
{
	int		list_size;
	int		index;
	t_env	*current;
	char	**converted_list;

	index = 0;
	list_size = check_size(env);
	current = env;
	converted_list = (char **)malloc(sizeof(char *) * list_size + 1);
	if (!converted_list)
		malloc_exit();
	while (index < list_size)
	{
		converted_list[index] = ft_strdup(current->env_str);
		index++;
		current = current->next;
	}
	return (converted_list);
}

char	**list_convert_env(t_env *env)
{
	int		list_size;
	int		index;
	t_env	*current;
	char	**converted_list;

	index = 0;
	list_size = check_size_value(env);
	current = env;
	converted_list = (char **)malloc(sizeof(char *) * list_size + 1);
	while (current)
	{
		if (current->var[1])
			converted_list[index] = ft_strdup(current->env_str);
		index++;
		current = current->next;
	}
	return (converted_list);
}

char	**list_convert_full(t_env *env)
{
	int		list_size;
	int		index;
	t_env	*current;
	char	**converted_list;

	index = 0;
	list_size = check_size(env);
	current = env;
	converted_list = (char **)malloc(sizeof(char *) * (list_size + 1));
	if (!converted_list)
	{
		perror("Malloc failed");
		exit(0);
	}
	while (index < list_size)
	{
		converted_list[index] = ft_strdup(current->env_str);
		index++;
		current = current->next;
	}
	converted_list[index] = NULL;
	return (converted_list);
}
