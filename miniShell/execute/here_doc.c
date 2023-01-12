/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:03 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:07 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	std_in(char *delim, int fd)
{
	char	*red;
	int		len;

	len = ft_strlen(delim);
	while (1)
	{
		red = readline("> ");
		if (!red)
			return ;
		if (ft_strncmp(red, delim, len + 1) == 0)
			break ;
		write(fd, red, ft_strlen(red));
		write(fd, "\n", 1);
		free(red);
	}
}

void	uniq_delim(int fd, char *delim, int out)
{
	char	*red;
	int		len;

	len = ft_strlen(delim);
	while (1)
	{
		red = get_next_line(fd);
		if (!red)
			return ;
		if (ft_strncmp(red, delim, len) == 0 && red[len + 1] == '\0')
			break ;
		write(out, red, ft_strlen(red));
		free(red);
	}
	free(red);
}

void	just_read(int fd, int out)
{
	char	*red;

	while (1)
	{
		red = get_next_line(fd);
		if (!red)
			return ;
		write(out, red, ft_strlen(red));
		free(red);
	}
}

int	here_doc(int fd, char *delim)
{
	int	out[2];

	if (pipe(out) < 0)
		return (err_int("PIPE_ERROR MArio didnt fit through"));
	if (fd == 0 && delim)
		std_in(delim, out[1]);
	else if (delim)
		uniq_delim(fd, delim, out[1]);
	else
		just_read(fd, out[1]);
	close(out[1]);
	return (out[0]);
}
