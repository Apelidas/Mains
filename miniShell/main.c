/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:35:57 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:35:59 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

void	test_exec(char *in, t_env **env)
{
	t_lst	*lst;
	char	**envp;

	envp = list_convert_full(*env);
	if (!envp)
		return ;
	lst = input_check(in, envp);
	free_split(envp);
	if (!lst)
		return ;
	print_lst(lst);
	execute(lst, env);
}

void	free_shell(t_env **env)
{
	write(1, "\n", 1);
	free_env(*env);
	close(0);
	close(1);
	exit(1);
}

void	run_shell(t_env **env)
{
	char	*str;
	char	**envp;
	t_lst	*lst;

	while (1)
	{
		str = readline("We test a prompt>> ");
		if (!str || g_status == -1)
			free_shell(env);
		else if (ft_strlen(str) != 0)
		{
			add_history(str);
			envp = list_convert_full(*env);
			lst = input_check(str, envp);
			print_lst(lst);
			free(str);
			free_split(envp);
			if (!lst)
				continue ;
			execute(lst, env);
			if (g_status == -1)
				break ;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = NULL;
	g_status = 0;
	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	create_env_list(&env, envp);
	run_shell(&env);
	envp[0] = "0";
	argc = argc + 1;
	if (!argv)
		exit(0);
}
