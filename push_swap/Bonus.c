/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:55:38 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/06/19 01:55:38 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_r(char *com, t_head *header)
{
	if (*com == 'r')
	{
		com++;
		if (*com == 'b')
			rotate(&(header->stackb), NULL);
		else if (*com == 'a')
			rotate(&(header->stacka), NULL);
		else if (!com[1])
			rr(header, NULL);
		else if (com[1] == 'a')
			rotate_rev(&(header->stacka), NULL);
		else if (com[1] == 'b')
			rotate_rev(&(header->stackb), NULL);
		else
			rrr(header, NULL);
	}
}

void	check_ps(char *com, t_head *header)
{
	if (*com == 'p')
	{
		com++;
		if (*com == 'a')
			pusha(header, NULL);
		else
			pushb(header, NULL);
	}
	else if (*com == 's')
	{
		com++;
		if (*com == 'a')
			swap(&(header->stacka), NULL);
		else if (*com == 'b')
			swap(&(header->stackb), NULL);
		else
			ss(header, NULL);
	}
}

void	reader(t_head *header)
{
	char	*red;
	char	buf;
	int		len;
	int		i;

	red = malloc(sizeof(char) * 4);
	red[3] = '\0';
	i = 0;
	len = 1;
	while (len > 0)
	{
		len = read(0, &buf, 1);
		red[i] = buf;
		i += len;
		if (buf == '\n')
		{
			red[i - 1] = '\0';
			check_r(red, header);
			check_ps(red, header);
			i = 0;
			red[i - 2] = '\0';
		}
	}
	free(red);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_head	*header;

	if (argc == 1)
		return (0);
	array = malloc(sizeof(int) * (argc - 1));
	if (!check_input(argv, array, argc - 1))
	{
		write(2, "ERROR\n", 6);
		return (0);
	}
	header = create_header(argc - 1);
	header->stacka = start_list(array, argc - 1);
	header->sizea = argc - 1;
	reader(header);
	if (is_sorted(header))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_all(header);
	free(array);
}
