/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:43:41 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/23 11:34:01 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_pos(int amount, t_head *header)
{
	int		i;
	t_list	*tmp;

	if (!header->stackb)
		return (0);
	i = 0;
	tmp = header->stackb;
	while (i < amount && tmp->pos > header->stacka->pos)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_length_logic(int *comp, int csize, int i)
{
	int	out;
	int	j;

	out = 0;
	j = 0;
	while (i > 0)
	{
		if (comp[csize - 1 - i] - j < j + comp[i])
		{
			out += comp[csize - 1 - i];
			j = comp[csize - 1 - i];
		}
		else
		{
			j = comp[i];
		}
		i--;
	}
	free(comp);
	return (out);
}

int	find_length(t_list *stacka, int low, int high, int csize)
{
	int		*comp;
	int		i;
	int		j;
	t_list	*tmp;
	int		out;

	tmp = stacka;
	comp = ft_calloc(csize, sizeof(int));
	i = 0;
	j = 0;
	while (tmp->next != stacka && i < csize - 1)
	{
		if (tmp->pos <= high && tmp->pos >= low)
		{
			comp[i] = j;
			i++;
		}
		j++;
		tmp = tmp->next;
	}
	out = find_length_logic(comp, csize, i);
	return (out);
}

int	find_elem(t_list *stack, int pos)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp->pos != pos)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_closest(t_list *stack, int low, int high)
{
	t_list	*tmp;
	int		front;
	int		back;
	int		out;

	front = 0;
	back = 0;
	tmp = stack;
	while ((stack->pos < low || stack->pos > high) && stack->next != tmp)
	{
		stack = stack->next;
		front++;
	}
	if (stack->pos < low || stack->pos > high)
		return (-1);
	out = stack->pos;
	stack = tmp;
	while ((stack->pos < low || stack->pos > high) && stack->prev != tmp)
	{
		stack = stack->prev;
		back++;
	}
	if (back < front)
		return (stack->pos);
	return (out);
}
