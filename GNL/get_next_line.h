/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:01:07 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/04/20 16:26:45 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		search_str(char *string, char del);
void	ft_strlcpy(char *dest, const char *src, int len);
void	strcut(char *tocut);
char	*stradd(char *front, char *back, int blen);
char	*gnl_create(int *len);

#endif