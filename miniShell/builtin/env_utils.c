/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:32:56 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:32:56 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	malloc_exit(void)
{
	perror("Malloc failed");
	exit(0);
}

char	*copy_before_equal(char	*str)
{
	int		i;
	char	*var;

	i = 0;
	while (str[i] != '=')
		i++;
	var = (char *)malloc(sizeof(char) * i + 1);
	if (!var)
		malloc_exit();
	var[i] = '\0';
	i = 0;
	while (str[i] != '=')
	{
		var[i] = str[i];
		i++;
	}
	return (var);
}

char	*copy_after_equal(char	*str)
{
	int		i;
	int		index;
	char	*value;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	index = 0;
	while (str[i + index])
		index++;
	value = (char *)malloc(sizeof(char) * index + 1);
	if (!value)
		malloc_exit();
	value[index] = '\0';
	index = 0;
	while (str[i + index])
	{
		value[index] = str[i + index];
		index++;
	}
	return (value);
}

/*
mallocs 2D of argument after and before an '=' sign if found.
*/
char	**env_and_value(char *str)
{
	char	**environment_variable;

	if (ft_strrchr(str, '='))
	{
		environment_variable = ft_calloc(3, sizeof(char *));
		if (!environment_variable)
			malloc_exit();
		environment_variable[0] = copy_before_equal(str);
		environment_variable[1] = copy_after_equal(str);
	}
	else
	{
		environment_variable = ft_calloc(2, sizeof(char *));
		if (!environment_variable)
			malloc_exit();
		environment_variable[0] = ft_strdup(str);
		environment_variable[1] = NULL;
	}
	return (environment_variable);
}

/*
Following the bash behavior variables from the environmental variables
are only being printed when they have value.
e.g. :"ZZ=..."
It can happen, that export can add a variable without value.
In this case export shows the variable but the bash cmd ENV doesn't.
*/
void	print_env(t_env *head)
{
	t_env	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->var[1])
			printf(" %s\n", tmp->env_str);
		tmp = tmp->next;
	}
	g_status = 0;
}
