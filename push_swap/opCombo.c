/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opCombo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:15:06 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/16 15:06:46 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ss(t_head *header, char *print)
{
	if (print)
		write(1, "ss\n", 3);
	swap(&(header->stacka), NULL);
	swap(&(header->stackb), NULL);
}

void	rr(t_head *header, char *print)
{
	if (print)
		write(1, "rr\n", 3);
	rotate(&(header->stacka), NULL);
	rotate(&(header->stackb), NULL);
}

void	rrr(t_head *header, char *print)
{
	if (print)
		write(1, "rrr\n", 4);
	rotate_rev(&(header->stacka), NULL);
	rotate_rev(&(header->stackb), NULL);
}

void	execute_command(char c, char s)
{
	if (c == '0' || c == '1')
		write(1, "s", 1);
	else if (c == '2')
	{
		write(1, "pa", 2);
		s = 'C';
	}
	else if (c == '3')
	{
		write(1, "pb", 2);
		s = 'C';
	}
	else if (c == '4' || c == '5')
		write(1, "r", 1);
	else if (c == '6')
		write(1, "rr", 2);
	if (s == 'a' || s == 'b')
		write (1, &s, 1);
	else if (c == '4' || c == '6')
		write(1, "r", 1);
	else if (c == '0')
		write(1, "s", 1);
	write(1, "\n", 1);
}

void	det_combo(t_head *h)
{
	int		a;
	int		b;
	char	*ca;
	char	*cb;

	ca = h->a;
	cb = h->b;
	a = 0;
	b = 0;
	while (ca[a] != '!' && cb[b] != '!' && ca[a] && cb[b] && ca[a] != '3')
	{
		if (h->a[a] == h->b[b])
		{
			execute_command(h->b[b], 'c');
			b++;
		}
		else
			execute_command(h->a[a], 'a');
		a++;
	}
	clean_det_combo(h, a, b);
}
