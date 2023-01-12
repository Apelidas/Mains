/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:59 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:59 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	end(t_lst *lst, int file, t_env *env)
{
	int	pid;
	int	wstatus;

	pid = fork();
	if (pid < 0)
	{
		write(2, "NO children to steal from hamelin\n", 34);
		return ;
	}
	if (pid == 0)
		child(lst, -1, file, env);
	close(file);
	wait(&wstatus);
	g_status = WEXITSTATUS(wstatus);
}

void	execute(t_lst *lst, t_env **env)
{
	if (lst_len(lst) == 1)
		single(lst, env);
	else
		parent(lst, 0, *env);
	destroy_lst(lst);
}
