/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:36:42 by ydimitro          #+#    #+#             */
/*   Updated: 2022/12/09 19:36:42 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *game)
{
	game->map.collectible = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		error_msg("Couldn't find mlx pointer.", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		error_msg("Couldn't create a Window.", game);
	}
}

void	init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = new_sprite(mlx, WALL_XPM, game);
	game->floor = new_sprite(mlx, FLOOR_XPM, game);
	game->collectible = new_sprite(mlx, COLLECTIBLE_XPM, game);
	game->player = new_sprite(mlx, PLAYER_XPM, game);
	game->open_exit = new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = new_sprite(mlx, EXIT_CLOSED_XPM, game);
}

t_image	new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error_msg("Couldn't find a sprite. Does it exist?", game);
	return (sprite);
}
