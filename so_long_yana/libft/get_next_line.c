/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:16:15 by ydimitro          #+#    #+#             */
/*   Updated: 2022/05/14 15:38:55 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*move_line(char *s)
{
	char	*dest;

	if (!s)
		return (NULL);
	dest = ft_strchr(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*dest;
	char		buffer[BUFFER_SIZE + 1];
	int			size;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	if (s)
		dest = ft_substr(s, 0, ft_strchr(s, '\n') - s + 1);
	else
		return (NULL);
	s = move_line(s);
	return (dest);
}
