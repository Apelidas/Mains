/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:23:26 by ydimitro          #+#    #+#             */
/*   Updated: 2022/12/09 19:23:26 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	print_movements(game);
	return (0);
}

void	identify_sprite(t_game *game, int y, int x)
{	
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == WALL)
		render_sprite (game, game->wall, y, x);
	else if (parameter == FLOOR)
		render_sprite (game, game->floor, y, x);
	else if (parameter == COLLECTIBLE)
		render_sprite (game, game->collectible, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.collectible == 0)
			render_sprite (game, game->open_exit, y, x);
		else
			render_sprite (game, game->exit_closed, y, x);
	}
	else if (parameter == PLAYER)
		render_sprite (game, game->player, y, x);
}


void	render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

void	print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}
