/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsingle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:05:35 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/16 15:07:54 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *toprint)
{
	t_list	*tmp;

	if (toprint)
	{
		write(1, toprint, 2);
		write(1, "\n", 1);
	}
	if (!*stack || *stack == (*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next->prev = (*stack);
	tmp->next = (*stack);
	tmp->prev = (*stack)->prev;
	tmp->prev->next = tmp;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

void	pusha(t_head *header, char *print)
{
	t_list	*tmp;

	if (print)
		write(1, "pa\n", 3);
	if (!header->stackb)
		return ;
	tmp = header->stackb->next;
	tmp->prev = header->stackb->prev;
	tmp->prev->next = tmp;
	header->stackb->next = header->stackb;
	header->stackb->prev = header->stackb;
	list_addtop(&(header->stacka), header->stackb);
	header->sizea++;
	header->sizeb--;
	header->stackb = tmp;
	if (header->sizeb == 0)
		header->stackb = NULL;
}

void	pushb(t_head *header, char *print)
{
	t_list	*tmp;

	if (print)
		write(1, "pb\n", 3);
	if (!header->stacka)
		return ;
	tmp = header->stacka->next;
	tmp->prev = header->stacka->prev;
	tmp->prev->next = tmp;
	header->stacka->next = header->stacka;
	header->stacka->prev = header->stacka;
	list_addtop(&(header->stackb), header->stacka);
	header->sizeb++;
	header->sizea--;
	header->stacka = tmp;
	if (header->sizea == 0)
		header->stacka = NULL;
}

void	rotate(t_list **stack, char *toprint)
{
	if (!*stack)
		return ;
	if (toprint)
	{
		write(1, toprint, 2);
		write(1, "\n", 1);
	}
	if (!*stack)
		return ;
	*stack = (*stack)->next;
}

void	rotate_rev(t_list **stack, char *toprint)
{
	if (toprint)
	{
		write(1, toprint, 3);
		write(1, "\n", 1);
	}
	if (!*stack)
		return ;
	*stack = (*stack)->prev;
}
