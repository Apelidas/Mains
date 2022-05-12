/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:09:44 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/04/20 16:23:33 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_create(int *len)
{
	*len = 1;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	red[BUFFER_SIZE + 1];
	int			len;

	if (fd < 0 || fd > 4096)
		return (NULL);
	out = gnl_create(&len);
	while (len != 0)
	{
		if (!*red)
		{
			len = read(fd, red, BUFFER_SIZE);
			if (len == -1)
				return (NULL);
		}
		else
		{
			len = search_str(red, '\n');
			out = stradd(out, red, len);
			if (red[len - 1] == '\n')
				len = 0;
			strcut(red);
		}
	}
	return (out);
}
