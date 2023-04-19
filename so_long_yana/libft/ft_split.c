/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:13:34 by ydimitro          #+#    #+#             */
/*   Updated: 2022/01/07 17:55:26 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *str, char c)
{
	int	str_nbr;
	int	i;

	str_nbr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i +1])
				i++;
			str_nbr++;
		}
		i++;
	}
	return (str_nbr);
}

static int	find_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static int	find_start(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		start;
	int		len;
	int		str_nbr;
	int		i;

	if (!s)
		return (NULL);
	str_nbr = count_strings(s, c);
	split = ft_calloc((str_nbr + 1), sizeof(char *));
	if (!split)
		return (NULL);
	start = find_start(s, c);
	i = 0;
	while (i < str_nbr)
	{
		len = find_len(&s[start], c);
		split[i] = ft_substr(s, start, len);
		start = start + len + find_start(&s[start + len], c);
		i++;
	}
	return (split);
}
