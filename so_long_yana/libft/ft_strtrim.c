/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:01:06 by ydimitro          #+#    #+#             */
/*   Updated: 2022/01/06 21:35:22 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char const *set, char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;
	size_t	len;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && ft_set(set, *start))
		start++;
	while (start < end && ft_set(set, *(end - 1)))
		end--;
	len = end - start + 1;
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, start, len);
	return (ret);
}
