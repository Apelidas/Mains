/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:23:26 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/17 16:39:18 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *tocheck)
{
	int	i;

	i = 0;
	if (*tocheck == '-' && tocheck[1] >= '0' && tocheck[1] <= '9')
			i = 1;
	while (tocheck[i] <= '9' && tocheck[i] >= '0')
		i++;
	return (i);
}

int	check_input(char **tocheck, int *array, int argc)
{
	int			i;
	int			k;
	long int	num;

	k = 1;
	while (k <= argc)
	{
		i = check_num(tocheck[k]);
		if (tocheck[k][i])
			return (0);
		num = ft_atoi(tocheck[k]);
		if (!(num <= 2147483647 && num >= -2147483648))
			return (0);
		i = 0;
		while (i <= (argc) && i < k - 1)
		{
			if (num == array[i])
				return (0);
			i++;
		}
		array[k - 1] = (int) num;
		k++;
	}
	return (1);
}

void	first_step(t_list *stack, int *input, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (stack->pos == input[i])
		{
			stack->pos = i;
			break ;
		}
		i++;
	}
}

void	assign_pos(t_list *stack, int *input, int n)
{
	int		i;
	t_list	*help;

	help = stack;
	sort(input, n);
	first_step(stack, input, n);
	stack = stack->next;
	while (stack != help)
	{
		i = 0;
		while (i < n)
		{
			if (stack->pos == input[i])
			{
				stack->pos = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}
