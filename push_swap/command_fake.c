/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fake.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:55:23 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/16 15:02:22 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_fake(t_list **stack, char *string)
{
	swap(stack, NULL);
	string_append(string, '0');
}

void	rotate_fake(t_list **stack, char *string)
{
	rotate(stack, NULL);
	string_append(string, '4');
}

void	rotate_rev_fake(t_list **stack, char *string)
{
	rotate_rev(stack, NULL);
	string_append(string, '6');
}

void	pusha_fake(t_head *header)
{
	pusha(header, NULL);
	string_append(header->b, '2');
}

void	pushb_fake(t_head *header)
{
	pushb(header, NULL);
	string_append(header->a, '3');
}
