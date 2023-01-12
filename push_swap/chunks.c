/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:24:48 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/05/24 00:24:48 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_chunk(t_head *header)
{
	while (header->sizeb > 0)
		pusha(header, "pa");
}

void	move_b_fake(t_head *header, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		j++;
		rotate_fake(&(header->stackb), header->b);
	}
	pushb_fake(header);
	clean_commands(header);
	det_combo(header);
	while (j > 0)
	{
		rotate_rev_fake(&(header->stackb), header->b);
		j--;
	}
}

void	push_chunk(t_head *header, int l, int h)
{
	int		i;
	int		count;
	int		help;

	i = l;
	while (i <= h)
	{
		help = find_closest(header->stacka, l, h);
		if (help != -1)
			move_to(header, help);
		else
			break ;
		count = find_insert_pos(i - l, header);
		move_b_fake(header, count);
		i++;
	}
	if (l < header->l)
		header->l = l;
	else
		header->h = h;
}

int	deter_next_chunk(t_head *h)
{
	int		out;
	int		comp;

	out = -1;
	comp = -1;
	if (h->sizea <= 0)
		return (0);
	if (h->l > 0)
		out = find_length(h->stacka, h->l - h->csize, h->l - 1, h->csize) + 3;
	if (h->h < h->sizea + h->sizeb - h->csize)
		comp = find_length(h->stacka, h->h + 1, h->h + h->csize, h->csize);
	if (out != -1 && comp != -1)
	{
		if (out < comp)
			return (-1);
		else
			return (1);
	}
	else if (out != -1)
		return (-1);
	else if (comp != -1)
		return (1);
	else
		return (0);
}

void	deter_chunk(t_head *header)
{
	int	l;

	if (header->sizea < 9)
		header->l = 0;
	else
	{
		l = header->sizea / 2;
		while (l % header->csize != 0)
			l++;
		header->l = l;
	}
	header->h = header->l + header->csize - 1;
}
