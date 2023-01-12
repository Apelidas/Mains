/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:04:33 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/17 15:35:38 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_elem(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = new;
	new->prev = new;
	return (new);
}

void	free_list(t_list *elem)
{
	t_list	*tmp;
	t_list	*help;

	if (!elem)
		return ;
	tmp = elem->next;
	while (tmp != elem)
	{
		help = tmp;
		tmp = tmp->next;
		free(help);
	}
	free(elem);
}

void	list_addback(t_list **stack, t_list *toadd)
{
	t_list	*tmp;

	if (!(*stack))
	{
		*stack = toadd;
		return ;
	}
	tmp = (*stack)->prev;
	tmp->next = toadd;
	(*stack)->prev = toadd;
	toadd->prev = tmp;
	toadd->next = *stack;
}

void	list_addtop(t_list **stack, t_list *toadd)
{
	list_addback(stack, toadd);
	(*stack) = toadd;
}

t_list	*start_list(int *input, int n)
{
	t_list	*stack;
	t_list	*tmp;
	int		i;

	i = 0;
	stack = NULL;
	while (i < n)
	{
		tmp = create_elem();
		tmp->pos = input[i];
		list_addback(&stack, tmp);
		i++;
	}
	assign_pos(stack, input, n);
	return (stack);
}
