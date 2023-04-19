/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:01 by ydimitro          #+#    #+#             */
/*   Updated: 2022/12/09 19:47:01 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	victory(t_game *game)
{
	ft_printf(CYAN"\n			Movements: %d\n"RESET, ++game->movements);
	free_all_allocated_memory(game);
	ft_printf(GREEN"\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
"RESET);
	exit (EXIT_FAILURE);
}

int	close_game(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, game->movements);
	free_all_allocated_memory(game);
	ft_printf(GREY"CLOSED\n"RESET);
	exit (EXIT_FAILURE);
}

int	error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		free_map(game);
	free(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit (EXIT_FAILURE);
}
