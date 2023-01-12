/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:20:31 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/19 15:15:08 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_commands(t_head *h)
{
	char	*tmp;
	int		i;
	int		b;

	i = 0;
	while (h->b[i] != '!' && h->b[i])
	{
		b = 0;
		if ((h->b[i] == '4' && h->b[i + 1] == '6'))
			b = 1;
		else if (h->b[i] == '6' && h->b[i + 1] == '4')
			b = 1;
		if (b == 1)
		{
			h->b[i] = '\0';
			h->b[i + 1] = '\0';
			tmp = ft_strjoin(h->b, &(h->b[i + 2]));
			free (h->b);
			h->b = tmp;
			clean_commands(h);
		}
		i++;
	}
}

void	clean_det_combo(t_head *h, int a, int b)
{
	while (h->b[b] != '!' && h->b[b])
	{
		execute_command(h->b[b], 'b');
		b++;
	}
	while (h->a[a] != '!' && h->a[a])
	{
		execute_command(h->a[a], 'a');
		a++;
	}
	ft_memset(h->a, '!', a);
	free(h->b);
	h->b = create_string((h->sizea + h->sizeb) / 2 + 2);
}

void	string_append(char *string, char c)
{
	while (*string >= '0' && *string <= '7' && *string)
		string++;
	if (!*string)
		return ;
	*string = c;
}

t_list	*copy_lst(t_list *tocpy)
{
	t_list	*tmp;
	t_list	*out;
	t_list	*help;

	tmp = tocpy;
	out = NULL;
	while (tmp->next != tocpy)
	{
		help = create_elem();
		help->pos = tmp->pos;
		list_addback(&out, help);
		tmp = tmp->next;
	}
	help = create_elem();
	help->pos = tmp->pos;
	list_addback(&out, help);
	return (out);
}

void	free_all(t_head *header)
{
	if (!header)
		return ;
	if (header->stacka)
		free_list(header->stacka);
	if (header->stackb)
		free_list(header->stackb);
	free_header(header);
}
