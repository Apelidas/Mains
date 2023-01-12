/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:10 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:13 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	guardian(t_lst *lst, int out, int *in)
{
	int	fd;

	if (!lst->cmd[0])
	{
		close(*in);
		close(out);
		write(2, "Syntax Error: unexpected end of file\n", 37);
		exit(1);
	}
	fd = 0;
	if (lst->delim || lst->fd_in > 2)
		fd = here_doc(lst->fd_in, lst->delim);
	if (fd != 0)
	{
		close(*in);
		*in = fd;
	}
	fd = out;
	if (lst->fd_out > 2)
		fd = lst->fd_out;
	dup2(*in, 0);
	dup2(fd, 1);
	return (fd);
}

void	work(int *fd, t_lst *lst, t_env *env, int file)
{
	int	wstatus;

	close(fd[1]);
	if (file > 2)
		close(file);
	wait(&wstatus);
	g_status = WEXITSTATUS(wstatus);
	if (!lst->next->next)
		end(lst->next, fd[0], env);
	else
		parent(lst->next, fd[0], env);
	close(fd[0]);
}

int	parent(t_lst *lst, int file, t_env *env)
{
	int	pid;
	int	fd[2];

	if (!lst)
		return (1);
	if (pipe(fd) < 0)
		return (err_int_id(2, "No child left Hamelin", lst));
	pid = fork();
	if (pid < 0)
		return (err_int_id(2, "NO children to steal from hamelin", lst));
	if (pid == 0)
		child(lst, fd[1], file, env);
	if (pid > 0)
	{
		work(fd, lst, env, file);
	}
	return (1);
}

void	builder(t_lst *lst, t_env **env)
{
	int	fd;

	fd = dup(1);
	if (lst->fd_out != 1)
		dup2(lst->fd_out, 1);
	just_built_it(env, lst->cmd, lst);
	if (lst->fd_in > 2)
		close(lst->fd_in);
	if (lst->fd_out > 2)
		close(lst->fd_out);
	dup2(fd, 1);
}
