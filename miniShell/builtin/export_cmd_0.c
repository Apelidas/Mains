/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:07 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:07 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_by_index(t_env *env)
{
	int		nbr;
	int		list_size;
	t_env	*current;

	nbr = 1;
	list_size = check_size(env);
	while (nbr <= list_size)
	{
		current = env;
		while (current->index != nbr)
			current = current->next;
		if (current->var[1])
			printf("declare -x %s=\"%s\"\n", current->var[0], current->var[1]);
		else
			printf("declare -x %s\n", current->var[0]);
		nbr++;
	}
}

/*
	-we check for the biggest string
	-give it the size of the list
	-mark it as checked
	-then go to through the list
	- */
char	*unchecked_str(t_env *env, char *biggest)
{
	t_env	*current;

	current = env;
	while (current->check != 0 && current)
		current = current->next;
	if (current)
	{
			biggest = current->env_str;
	}
	while (current)
	{
		if (compare_str(biggest, current->env_str) < 0 && current->check == 0)
			biggest = current->env_str;
		else
			current = current->next;
	}
	return (biggest);
}

void	export_no_arg(t_env *env)
{
	add_index(env);
	print_by_index(env);
	reset_index(env);
	g_status = 0;
}

void	export_cmd(t_env *env_list, char **arguments)
{
	int	arg_count;

	arg_count = 0;
	while (arguments[arg_count])
		arg_count++;
	if (arg_count == 1)
		export_no_arg(env_list);
	else
		export_arg(env_list, arguments);
}
