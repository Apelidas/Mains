/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:41 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:41 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_command(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

char	*delim(char *string, int i)
{
	char	*out;
	int		len;
	char	check;
	int		help;

	help = i;
	len = 0;
	check = ' ';
	i = skip_whitesp(string, i + 1);
	if (string[i] == '"' || string[i] == '\'')
		check = string[i];
	while (string[i + len] && string[i + len] != check)
		len++;
	if (is_command(string[i + len - 1]))
		len--;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (err("MALLOC_ERROR delim"));
	ft_strlcpy(out, &string[i], len + 1);
	remove_quotes(out);
	delicut(string, len, help);
	return (out);
}

int	lesser(char **cmd, t_lst *lst, int i)
{
	if (cmd[0][i] == '<')
	{
		if ((cmd[0][i + 1]) == '<')
		{
			i++;
			if (lst->delim)
				free(lst->delim);
			lst->delim = delim(*cmd, i);
			if (!lst->delim)
				return (-1);
		}
		else
		{
			if (lst->fd_in > 2)
				close(lst->fd_in);
			lst->fd_in = redirect_in(*cmd, i + 1);
		}
		i++;
		return (0);
	}
	return (i);
}

int	greater(char **cmd, t_lst *lst, int i)
{
	if (cmd[0][i] == '>')
	{
		if ((cmd[0][i + 1]) == '>')
		{
			i++;
			lst->append = 1;
		}
		else
			lst->append = 0;
		if (lst->fd_out > 2)
			close(lst->fd_out);
		lst->fd_out = redirect_out(*cmd, i + 1, lst->append);
		if (lst->fd_out == 0)
			return (-1);
		i++;
	}
	return (i);
}

int	search_arrow(char **cmd, t_lst *lst)
{
	int		i;

	i = 0;
	while (cmd[0][i])
	{
		i = skip_quotes(*cmd, i);
		if (!cmd[0][i])
			break ;
		i = lesser(cmd, lst, i);
		if (i == -1)
			return (0);
		i = skip_quotes(*cmd, i);
		if (!cmd[0][i])
			break ;
		i = greater(cmd, lst, i);
		if (i == -1)
			return (0);
		i++;
	}
	return (1);
}
