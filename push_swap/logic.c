/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:25:32 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/16 15:06:58 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_logic(t_list **stack)
{
	if ((*stack)->pos == (*stack)->next->pos + 1)
		swap(stack, "sa");
	else if ((*stack)->pos == (*stack)->next->pos - 2)
		swap(stack, "sa");
	if ((*stack)->pos > (*stack)->prev->pos)
	{
		if ((*stack)->pos > (*stack)->next->pos)
			rotate(stack, "ra");
		else
			rotate_rev(stack, "rra");
	}
}

void	sort_logic_rev(t_list **stack)
{
	if ((*stack)->pos == (*stack)->next->pos - 1)
		swap(stack, "sb");
	else if ((*stack)->pos == (*stack)->next->pos + 2)
		swap(stack, "sb");
	if ((*stack)->pos < (*stack)->prev->pos)
	{
		if ((*stack)->pos < (*stack)->next->pos)
			rotate(stack, "rb");
		else
			rotate_rev(stack, "rrb");
	}
}

void	move_b(t_head *header, int count, int *com)
{
	int	j;

	j = 0;
	while (j < count)
	{
		j++;
		rotate(&(header->stackb), NULL);
		(*com)++;
	}
	pushb(header, NULL);
	(*com)++;
	while (j > 0)
	{
		rotate_rev(&(header->stackb), NULL);
		j--;
		(*com)++;
	}
}
