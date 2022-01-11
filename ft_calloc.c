/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:05:26 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/01/10 13:38:35 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	mem = malloc(size * count);
	if (mem == NULL)
	{
		return (NULL);
	}
	ft_bzero(mem, count * size);
	return (mem);
}
