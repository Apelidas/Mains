/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:07:57 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/19 16:48:16 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *tosort, int n)
{
	int	i;
	int	k;
	int	swap;

	i = 0;
	while (i < n - 1)
	{
		k = i + 1;
		while (k < n)
		{
			if (tosort[i] > tosort[k])
			{
				swap = tosort[i];
				tosort[i] = tosort[k];
				tosort[k] = swap;
			}
			k++;
		}
		i++;
	}
}

void	move_to(t_head *header, int pos)
{
	int	ret;

	ret = find_elem(header->stacka, pos);
	if (ret > header->sizea / 2)
		ret = (header->sizea - ret) * (-1);
	while (ret != 0)
	{
		if (ret < 0)
		{
			rotate_rev_fake(&(header->stacka), header->a);
			ret++;
		}
		else if (ret > 0)
		{
			rotate_fake(&(header->stacka), header->a);
			ret--;
		}
	}
}

void	chunk_sort(t_head *header)
{
	int	i;
	int	next;

	if (header->csize == 0)
		return ;
	push_chunk(header, header->l, header->h);
	next = deter_next_chunk(header);
	while (next != 0)
	{
		if (next == 1)
			push_chunk(header, header->h + 1, header->h + header->csize);
		else
			push_chunk(header, header->l - header->csize, header->l -1);
		i = 0;
		while (next == -1 && i < header->csize)
		{
			rotate_fake(&(header->stackb), header->b);
			i++;
		}
		next = deter_next_chunk(header);
	}
}
