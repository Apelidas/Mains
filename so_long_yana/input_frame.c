/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:58:09 by ydimitro          #+#    #+#             */
/*   Updated: 2022/12/09 18:58:09 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_game *game)
{
	printf("moved: %d\n", key);
	if (key == KEY_UP || key == KEY_W)
		player_move(game, game->map.player.y - 1, game->map.player.x);
	if (key == KEY_LEFT || key == KEY_A)
		player_move(game, game->map.player.y, game->map.player.x - 1);
	if (key == KEY_RIGHT || key == KEY_D)
		player_move(game, game->map.player.y, game->map.player.x + 1);
	if (key == KEY_DOWN || key == KEY_S)
		player_move(game, game->map.player.y + 1, game->map.player.x);
	if (key == KEY_Q || key == KEY_ESC)
		close_game(game);
	return (0);
}

void	player_move(t_game *game, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.collectible == 0)
		victory(game);
	else if ((game->map.full[new_y][new_x] == FLOOR)
	|| (game->map.full[new_y][new_x] == COLLECTIBLE))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == COLLECTIBLE)
			game->map.collectible--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		render_map(game);
	}
}
