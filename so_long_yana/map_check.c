/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:59:53 by ydimitro          #+#    #+#             */
/*   Updated: 2022/12/09 18:59:53 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

void	check_map(t_game *game)
{
	check_rows(game);
	check_columns(game);
	count_map_parameters(game);
	verify_map_parameters(game);
}

void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		// printf("char %d\n", game->map.full[i][game->map.columns - 1]);
		if ((int) ft_strlen(game->map.full[i]) != game->map.columns)
			error_msg("Invalid Map. The Map must be rectangular!", game);
		else if (game->map.full[i][0] != WALL)
			error_msg("Invalid Map. There's a Wall missing from the first row.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			error_msg("Invalid Map. There's a Wall missing from the last row.\n\
The Map must be surrounded by walls!.", game);
		i++;
	}
}

void	check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			error_msg("Invalid Map. \
There's a Wall missing from the first column.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			error_msg("Invalid Map. \
There's a Wall missing from the last column.\n\
The Map must be surrounded by walls!.", game);
		i++;
	}
}

void	count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				error_msg("Invalid Map. Unexpected map parameter.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COLLECTIBLE)
				game->map.collectible++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	verify_map_parameters(t_game *game)
{
	if (game->map.collectible == 0)
		error_msg("Invalid Map. There are no Coins!", game);
	else if (game->map.exit == 0)
		error_msg("Invalid Map. There is no Exit.", game);
	else if (game->map.players != 1)
		error_msg("Invalid Map. Invalid Player quantity. \
It's a single player game.", game);
}
