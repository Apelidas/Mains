/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:29:29 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/17 16:35:55 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <time.h>
void print_array(int *array, int n);

void print_list(t_list *elem)
{
	t_list*tmp;

	if (!elem)
	{
		printf("\n");
		return;
	}
	tmp = elem->next;
	printf("%d", elem->pos);
	while (tmp != elem && tmp)
		{
			printf("|%d", tmp->pos);
			tmp = tmp->next;
		}
	printf("\n");
}

int	*create_random(int n)
{
	int ran;
	int i, j;
	int *array;

	array = malloc(sizeof(int) * n);
	srand(time(NULL));
	i = 0;
	while (i < n)
	{
		ran = rand() % n;
		j = 0;
		while (j < i)
		{
			if (array[j] == ran)
			{
				ran = rand() % n;
				j = -1;
			}
			j++;
		}
		array[i] = ran;
		i++;
	}
	return (array);
}

void print_array(int *array, int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		printf("%d ", array[i]);
	i++;
	}
	printf("\n");
}

int	is_sorted(t_head *header)
{
	t_list*	tmp;
	
	tmp =header->stacka;
	
	if (header->stackb != 0)
		return 1;
	while(tmp->pos + 1 == tmp->next->pos)
		tmp = tmp->next;
	if (tmp->next == header->stacka)
		return 0;
	return 1;
}