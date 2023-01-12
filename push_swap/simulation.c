/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:47:42 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/17 16:35:19 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deter_chunk_size(t_head *header)
{
	t_head	*sim;
	int		i;
	int		out;
	int		amount;
	int		j;

	i = 3;
	out = 3;
	amount = 200000;
	while (i < header->sizea / 4)
	{
		sim = cpy_header(header);
		sim->csize = i;
		deter_chunk(sim);
		j = chunk_sort_sim(sim);
		if (j <= amount)
		{
			amount = j;
			out = i;
		}
		free_all(sim);
		i++;
	}
	return (out);
}

int	chunk_sort_sim(t_head *h)
{
	int	i;
	int	next;
	int	com;

	com = push_chunk_sim(h, h->l, h->h);
	next = deter_next_chunk(h);
	while (next != 0)
	{
		if (next == 1)
			com += push_chunk_sim(h, h->h + 1, h->h + h->csize);
		else
			com += push_chunk_sim(h, h->l - h->csize, h->l -1);
		i = 0;
		while (next == -1 && i < h->csize)
		{
			rotate(&(h->stackb), NULL);
			i++;
			com++;
		}
		next = deter_next_chunk(h);
	}
	return (com);
}

int	push_chunk_sim(t_head *header, int low, int high)
{
	int		i;
	int		count;
	int		com;
	int		help;

	i = low;
	com = 0;
	while (i <= high)
	{
		help = find_closest(header->stacka, low, high);
		if (help != -1)
			com += move_to_sim(header, help);
		else
			break ;
		count = find_insert_pos(i - low, header);
		move_b(header, count, &com);
		i++;
	}
	if (low < header->l)
		header->l = low;
	else
		header->h = high;
	return (com);
}

int	merge_chunk_sim(t_head *header)
{
	while (header->sizeb > 0)
		pusha(header, NULL);
	return (header->sizeb);
}

int	move_to_sim(t_head *header, int pos)
{
	int	ret;
	int	i;

	i = 0;
	ret = find_elem(header->stacka, pos);
	if (ret > header->sizea / 2)
		ret = (header->sizea - ret) * (-1);
	while (ret != 0)
	{
		if (ret < 0)
		{
			rotate_rev(&(header->stacka), NULL);
			i++;
			ret++;
		}
		else if (ret > 0)
		{
			rotate(&(header->stacka), NULL);
			ret--;
			i++;
		}
	}
	return (i);
}
