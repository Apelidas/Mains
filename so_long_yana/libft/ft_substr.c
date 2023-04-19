/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:44:37 by ydimitro          #+#    #+#             */
/*   Updated: 2022/01/07 14:19:54 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a_str;
	size_t	len_s;
	size_t	len_a_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	a_str = malloc((len + 1) * sizeof(char));
	if (!a_str)
		return (NULL);
	len_s = start;
	len_a_str = 0;
	while (len_s < ft_strlen(s) && len_a_str < len)
		a_str[len_a_str++] = s[len_s++];
	a_str[len_a_str] = '\0';
	return (a_str);
}
