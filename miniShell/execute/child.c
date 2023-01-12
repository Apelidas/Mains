/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:56 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:56 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	only_child(t_lst *lst, t_env *env)
{
	char	**envp;

	envp = NULL;
	envp = list_convert_full(env);
	if (lst->fd_in != 0)
		dup2(lst->fd_in, 0);
	if (lst->fd_out != 1)
		dup2(lst->fd_out, 1);
	if (!envp)
		exit(-1);
	else
	{
		if (lst->fd_in > 2)
			close(lst->fd_in);
		if (lst->fd_out > 2)
			close(lst->fd_out);
		execve(lst->path, lst->cmd, envp);
		write(2, "Command could not be executed\n", 30);
	}
	free_split(envp);
	destroy_lst(lst);
	free_env(env);
	exit(127);
}

void	grandparent(t_lst *lst)
{
	int	fd;

	fd = 0;
	if (lst->delim || lst->fd_in > 2)
		fd = here_doc(lst->fd_in, lst->delim);
	if (fd != 0)
	{
		if (lst->fd_in > 2)
			close(lst->fd_in);
		lst->fd_in = fd;
	}
}

void	single(t_lst *lst, t_env **env)
{
	int	pid;
	int	wstatus;

	grandparent(lst);
	if (lst->build)
		builder(lst, env);
	else if (lst->cmd[0])
	{
		if (!lst->path)
			write(2, "Command not found\n", 18);
		else
		{
			pid = fork();
			if (pid < 0)
				err("No child to steal from hamelin");
			if (pid == 0)
				only_child(lst, *env);
			else
				wait(&wstatus);
			g_status = WEXITSTATUS(wstatus);
			dup2(0, 0);
		}
		dup2(1, 1);
	}
}

void	destroy_child(t_lst *lst, t_env *env)
{
	destroy_lst(lst);
	free_env(env);
	exit(127);
}

void	child(t_lst *lst, int out, int in, t_env *env)
{
	int		fd;
	char	**envp;

	fd = guardian(lst, out, &in);
	if (lst->build)
	{
		just_built_it(&env, lst->cmd, lst);
		close(fd);
	}
	else
	{
		close(fd);
		if (!lst->path)
			write(2, "Command not found\n", 18);
		else
		{
			envp = list_convert_full(env);
			execve(lst->path, lst->cmd, envp);
			g_status = 1;
			write(2, "Command could not be executed\n", 30);
			free_split(envp);
		}
	}
	destroy_child(lst, env);
}
