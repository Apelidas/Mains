/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:25:19 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/05/23 22:25:19 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_head	t_head;
typedef struct s_list	t_list;

struct	s_list
{
	t_list	*next;
	t_list	*prev;
	int		pos;
};

struct	s_head
{
	t_list	*stacka;
	int		sizea;
	t_list	*stackb;
	int		sizeb;
	int		l;
	int		h;
	int		csize;
	char	*a;
	char	*b;
};

//			Allowed Commands
void		swap(t_list**stack, char *toprint);
void		pusha(t_head *header, char *print);
void		pushb(t_head *header, char *print);
void		ss(t_head *header, char *print);
void		rotate(t_list**stack, char *toprint);
void		rr(t_head *header, char *print);
void		rotate_rev(t_list**stack, char *toprint);
void		rrr(t_head *header, char *print);

//			t_listCommands
t_list		*create_elem(void);
void		free_list(t_list*elem);
void		list_addback(t_list**stack, t_list*toadd);
void		list_addtop(t_list**stack, t_list*toadd);
t_list		*start_list(int *input, int n);
int			find_elem(t_list*stack, int pos);
int			find_closest(t_list*stack, int low, int high);
t_list		*copy_lst(t_list*tocpy);

//			Miscellanous
void		sort(int *tosort, int n);
int			check_input(char **tocheck, int *array, int argc);
void		assign_pos(t_list*stack, int *input, int n);

//			debug
void		print_list(t_list*elem);
int			*create_random(int n);
int			is_sorted(t_head *header);

//			Simulation
int			chunk_sort_sim(t_head *header);
int			push_chunk_sim(t_head *header, int low, int high);
int			merge_chunk_sim(t_head *header);
int			move_to_sim(t_head *header, int pos);
int			deter_chunk_size(t_head *header);
void		pushb_fake(t_head *header);
void		pusha_fake(t_head *header);
void		rotate_rev_fake(t_list**stack, char *string);
void		rotate_fake(t_list**stack, char *string);
void		swap_fake(t_list**stack, char *string);

void		sort_logic(t_list**stack);
void		chunk_sort(t_head *header);
void		merge_chunk(t_head *header);
void		sort_logic_rev(t_list**stack);
void		deter_chunk(t_head *header);
void		move_to(t_head *header, int ret);
int			deter_next_chunk(t_head *header);
void		push_chunk(t_head *header, int low, int high);
int			find_insert_pos(int amount, t_head *header);
int			find_length(t_list*stackA, int low, int high, int csize);
t_head		*create_header(int size);
void		free_all(t_head *header);
t_head		*cpy_header(t_head *header);
void		free_header(t_head *header);
char		*create_string(int size);
void		det_combo(t_head *header);
void		clean_commands(t_head *header);
void		move_b(t_head *header, int count, int *com);
void		clean_det_combo(t_head *h, int a, int b);
void		clean_commands(t_head *h);
void		string_append(char *string, char c);
void		execute_command(char c, char s);
#endif