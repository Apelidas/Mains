/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:31:19 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/16 15:03:36 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*create_header(int size)
{
	t_head	*new;

	new = malloc(sizeof(t_head));
	new->stacka = NULL;
	new->stackb = NULL;
	new->sizea = size;
	new->sizeb = 0;
	new->l = -1;
	new->h = -1;
	new->a = create_string(size / 2 + 2);
	new->b = create_string(size / 2 + 2);
	return (new);
}

t_head	*cpy_header(t_head *header)
{
	t_head	*out;

	out = create_header(header->sizea);
	out->stacka = copy_lst(header->stacka);
	out->sizea = header->sizea;
	return (out);
}

void	free_header(t_head *header)
{
	free(header->a);
	free(header->b);
	free(header);
}

char	*create_string(int size)
{
	char	*out;
	int		i;

	out = malloc(sizeof(char) * (size + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < size)
	{
		out[i] = '!';
		i++;
	}
	out[i] = '\0';
	return (out);
}
