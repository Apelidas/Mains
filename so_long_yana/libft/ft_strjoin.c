/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:27:42 by ydimitro          #+#    #+#             */
/*   Updated: 2022/01/04 13:09:00 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a_str;
	int		i;
	int		j;

	a_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !a_str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		a_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		a_str[i++] = s2[j++];
	a_str[i] = '\0';
	return (a_str);
}
