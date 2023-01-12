/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:49:23 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/05/23 22:49:23 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_6(t_head *header)
{
	if (!is_sorted(header))
		return ;
	if (header->sizea <= 3)
	{
		sort_logic(&(header->stacka));
	}
	else
	{
		move_to(header, 0);
		clean_commands(header);
		det_combo(header);
		pushb(header, "pb");
		move_to(header, 1);
		clean_commands(header);
		det_combo(header);
		pushb(header, "pb");
		sort_logic(&(header->stacka));
		sort_logic_rev(&(header->stackb));
		merge_chunk(header);
	}
}

void	start_sorting(t_head *header)
{
	if (!is_sorted(header))
		return ;
	deter_chunk(header);
	chunk_sort(header);
	if (header->h < header->sizea + header->sizeb)
		push_chunk(header, header->h + 1, header->sizea + header->sizeb - 1);
	det_combo(header);
	merge_chunk(header);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_head	*header;

	if (argc < 2)
		return (1);
	array = malloc(sizeof(int) * (argc - 1));
	if (!check_input(argv, array, argc - 1))
	{
		write(1, "Incorrect Input\n", 16);
		return (0);
	}
	header = create_header(argc - 1);
	header->stacka = start_list(array, argc - 1);
	header->sizea = argc - 1;
	if (header->sizea < 6)
		sort_less_6(header);
	else
	{
		header->csize = deter_chunk_size(header);
		start_sorting(header);
	}
	while (header->stacka->pos != 0)
		rotate_rev(&(header->stacka), "rra");
	free_all(header);
	free(array);
}
