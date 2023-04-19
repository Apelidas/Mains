/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:43:48 by ydimitro          #+#    #+#             */
/*   Updated: 2022/01/06 15:51:40 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (!ptr && !ptr2)
		return (NULL);
	i = 0;
	if (ptr2 < ptr)
	{
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	}
	else
	{
		while (len-- > 0)
			*(ptr++) = *(ptr2++);
	}
	return (dst);
}
